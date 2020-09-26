/*
 * MutexGuardUncertain.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_MUTEXGUARDUNCERTAIN_HPP_
#define BFFT_FRUTIL_MUTEXGUARDUNCERTAIN_HPP_


class MutexGuardUncertain
{
	Mutex &_mutex;

public:
	const bool isSuccess;

	MutexGuardUncertain(Mutex &mutex, Ticks ticksToWait, bool errorIfNotSucessful) :
		_mutex(mutex), isSuccess(mutex.tryTake(ticksToWait))
	{
		if (errorIfNotSucessful && !isSuccess) {errorCannotTakeMutex();}
	}

	~MutexGuardUncertain()
	{
		if (isSuccess) {_mutex.give();}
	}

	void assertIsAcquired()
	{
		if (!isSuccess) {errorCannotTakeMutex();}
	}
};


#endif /* BFFT_FRUTIL_MUTEXGUARDUNCERTAIN_HPP_ */
