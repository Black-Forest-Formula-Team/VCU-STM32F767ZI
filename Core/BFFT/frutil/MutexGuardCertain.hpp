/*
 * MutexGuardCertain.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_MUTEXGUARDCERTAIN_HPP_
#define BFFT_FRUTIL_MUTEXGUARDCERTAIN_HPP_


#include "Mutex.hpp"
#include "Ticks.hpp"


class MutexGuardCertain
{
	Mutex &_mutex;

public:
	MutexGuardCertain(Mutex &mutex, Ticks ticksToWait) : _mutex(mutex)
	{
		_mutex.take(ticksToWait);
	}

	~MutexGuardCertain()
	{
		_mutex.give();
	}
};


#endif /* BFFT_FRUTIL_MUTEXGUARDCERTAIN_HPP_ */
