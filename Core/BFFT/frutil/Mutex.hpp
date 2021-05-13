/*
 * Mutex.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_MUTEX_HPP_
#define BFFT_FRUTIL_MUTEX_HPP_


#include "FreeRTOS.h"
#include "semphr.h"
#include "mutex_errors.hpp"
#include "Ticks.hpp"
#include "SuspendSchedulerAndInterruptsGuard.hpp"


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
		if (xSemaphoreTake(_mutexHandle, ticksToWait.cxTicks) == pdTRUE) {return true;}
		else {return false;}
	}

	void take(Ticks ticksToWait)
	{
		if (!tryTake(ticksToWait.cxTicks)) {errorCannotTakeMutex();}
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


#endif /* BFFT_FRUTIL_MUTEX_HPP_ */
