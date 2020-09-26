/*
 * MutexAllocatedOnHeap.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_MUTEXALLOCATEDONHEAP_HPP_
#define BFFT_FRUTIL_MUTEXALLOCATEDONHEAP_HPP_


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


#endif /* BFFT_FRUTIL_MUTEXALLOCATEDONHEAP_HPP_ */
