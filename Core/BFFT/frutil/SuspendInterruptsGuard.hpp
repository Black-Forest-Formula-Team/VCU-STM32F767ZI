/*
 * SuspendInterruptsGuard.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_SUSPENDINTERRUPTSGUARD_HPP_
#define BFFT_FRUTIL_SUSPENDINTERRUPTSGUARD_HPP_


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


#endif /* BFFT_FRUTIL_SUSPENDINTERRUPTSGUARD_HPP_ */
