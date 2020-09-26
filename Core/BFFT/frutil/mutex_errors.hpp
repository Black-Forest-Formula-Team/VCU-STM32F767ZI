/*
 * mutex_errors.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_MUTEX_ERRORS_HPP_
#define BFFT_FRUTIL_MUTEX_ERRORS_HPP_


void errorMutexHandleIsNullptr();

void errorCannotDeleteMutex();

void errorCannotCreateMutexOnHeap();

void errorCannotGiveMutex();

void errorCannotTakeMutex();


#endif /* BFFT_FRUTIL_MUTEX_ERRORS_HPP_ */
