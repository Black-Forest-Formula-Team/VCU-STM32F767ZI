/*
 * MutexAllocatedLocally.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_MUTEXALLOCATEDLOCALLY_HPP_
#define BFFT_FRUTIL_MUTEXALLOCATEDLOCALLY_HPP_


#include "Mutex.hpp"


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


#endif /* BFFT_FRUTIL_MUTEXALLOCATEDLOCALLY_HPP_ */
