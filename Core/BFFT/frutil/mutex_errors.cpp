/*
 * mutex_errors.cpp
 *
 *  Created on: 17.09.2020
 *      Author: Alex
 */

#include "error.hpp"


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
