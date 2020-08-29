/*
 * FreeRTOSUtils.hpp
 *
 *  Created on: 13.08.2020
 *      Author: Alex
 */

#ifndef SRC_FRUTIL_FREERTOSUTILS_HPP_
#define SRC_FRUTIL_FREERTOSUTILS_HPP_

#include "FreeRTOS.h"
#include "semphr.h"

namespace frutil
{
	void error(const char* msg)
	{
		// TODO: implement.
		throw msg;
	}


	class Ticks
	{
	public:
		static const Ticks Max_Delay;

		const TickType_t ticks;

		Ticks(TickType_t ticks): ticks(ticks)
		{}

		static Ticks fromTicks(TickType_t ticks)
		{
			return Ticks(ticks);
		}

		static Ticks fromMs(unsigned long ms)
		{
			// TODO: check for overflow
			return Ticks(portTICK_RATE_MS * ms);
		}
	};
	const Ticks Ticks::Max_Delay = Ticks(0);


	class SuspendInterruptsGuard
	{
	public:
		SuspendInterruptsGuard()
		{
			portENTER_CRITICAL();
		}

		~SuspendInterruptsGuard()
		{
			portEXIT_CRITICAL();
		}
	};


	class SuspendSchedulerGuard
	{
	public:
		SuspendSchedulerGuard()
		{
			vTaskSuspendAll();
		}

		~SuspendSchedulerGuard()
		{
			xTaskResumeAll();
		}
	};


	class SuspendSchedulerAndInterruptsGuard
	{
		SuspendSchedulerGuard _suspendSchedulerGuard;
		SuspendInterruptsGuard _suspendInterruptsGuard;
	};
}


namespace frutil::mutex
{
	void errorMutexHandleIsNullptr()
	{
		error("Mutex handle is nullptr.");
	}

	void errorCannotDeleteMutex()
	{
		error("Cannot delete mutex. Mutex is in use.");
	}

	void errorCannotCreateMutexOnHeap()
	{
		error("Cannot create mutex on heap. Memory cannot be allocated.");
	}

	void errorCannotGiveMutex()
	{
		error("Mutex cannot be given.");
	}

	void errorCannotTakeMutex()
	{
		error("Mutex cannot be taken.");
	}


	class Mutex
	{
		const SemaphoreHandle_t _mutexHandle;

	public:
		Mutex(const SemaphoreHandle_t mutex) : _mutexHandle(mutex)
		{
			if (mutex == nullptr) {errorMutexHandleIsNullptr();}
		}

		~Mutex()
		{
			SuspendSchedulerAndInterruptsGuard();
			if (uxSemaphoreGetCount(_mutexHandle) != 0) {errorCannotDeleteMutex();}
			vSemaphoreDelete(_mutexHandle);
		}

		SemaphoreHandle_t mutexHandle()
		{
			return _mutexHandle;
		}

		bool tryTake(Ticks ticksToWait)
		{
			if (xSemaphoreTake(_mutexHandle, ticksToWait.ticks) == pdTRUE) {return true;}
			else {return false;}
		}

		void take(Ticks ticksToWait)
		{
			if (!tryTake(ticksToWait.ticks)) {errorCannotTakeMutex();}
		}

		bool tryGive()
		{
			if (xSemaphoreGive(_mutexHandle) == pdTRUE) {return true;}
			else {return false;}
		}

		void give()
		{
			if (!tryGive()) {errorCannotGiveMutex();}
		}

		bool tryTakeFromISR(bool &out_higherPriorityTaskWoken)
		{
			BaseType_t xHigherPriorityTaskWoken;
			if (xSemaphoreTakeFromISR(_mutexHandle, &xHigherPriorityTaskWoken) == pdTRUE)
			{
				out_higherPriorityTaskWoken = xHigherPriorityTaskWoken;
				return true;
			}
			else {return false;}
		}

		void takeFromISR(bool &out_higherPriorityTaskWoken)
		{
			if (!tryTakeFromISR(out_higherPriorityTaskWoken)) {errorCannotTakeMutex();}
		}

		bool tryGiveFromISR(bool &out_higherPriorityTaskWoken)
		{
			BaseType_t xHigherPriorityTaskWoken;
			if (xSemaphoreGiveFromISR(_mutexHandle, &xHigherPriorityTaskWoken) == pdTRUE)
			{
				out_higherPriorityTaskWoken = xHigherPriorityTaskWoken;
				return true;
			}
			else {return false;}
		}

		void giveFromISR(bool &out_higherPriorityTaskWoken)
		{
			if (!tryGiveFromISR(out_higherPriorityTaskWoken)) {errorCannotTakeMutex();}
		}
	};


	class MutexAllocatedOnHeap : public Mutex
	{
		static SemaphoreHandle_t createMutexOnHeap()
		{
			SemaphoreHandle_t mutex = xSemaphoreCreateMutex();
			if (mutex == nullptr) {errorCannotCreateMutexOnHeap();}
			return mutex;
		}

	public:
		MutexAllocatedOnHeap() : Mutex(createMutexOnHeap())
		{}
	};


	class MutexAllocatedLocally : public Mutex
	{
		StaticSemaphore_t _mutexInstance;
	public:
		MutexAllocatedLocally() : Mutex(xSemaphoreCreateMutexStatic(&_mutexInstance))
		{}

		StaticSemaphore_t mutexInstance()
		{
			return _mutexInstance;
		}
	};


	class MutexUncertainGuard
	{
		Mutex &_mutex;

	public:
		const bool isSuccess;

		MutexUncertainGuard(Mutex &mutex, Ticks ticksToWait, bool errorIfNotSucessful) :
			_mutex(mutex), isSuccess(mutex.tryTake(ticksToWait))
		{
			if (errorIfNotSucessful && !isSuccess) {errorCannotTakeMutex();}
		}

		~MutexUncertainGuard()
		{
			if (isSuccess) {_mutex.give();}
		}

		void assertIsAcquired()
		{
			if (!isSuccess) {errorCannotTakeMutex();}
		}
	};

	class MutexCertainGuard
	{
		Mutex &_mutex;

	public:
		MutexCertainGuard(Mutex &mutex, Ticks ticksToWait) : _mutex(mutex)
		{
			_mutex.take(ticksToWait);
		}

		~MutexCertainGuard()
		{
			_mutex.give();
		}
	};
}


#endif /* SRC_FRUTIL_FREERTOSUTILS_HPP_ */
