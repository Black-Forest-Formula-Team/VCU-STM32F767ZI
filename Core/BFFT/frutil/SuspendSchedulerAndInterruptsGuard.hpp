/*
 * SuspendSchedulerAndInterruptsGuard.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_SUSPENDSCHEDULERANDINTERRUPTSGUARD_HPP_
#define BFFT_FRUTIL_SUSPENDSCHEDULERANDINTERRUPTSGUARD_HPP_


#include "SuspendSchedulerGuard.hpp"
#include "SuspendInterruptsGuard.hpp"


class SuspendSchedulerAndInterruptsGuard
{
	SuspendSchedulerGuard _suspendSchedulerGuard;
	SuspendInterruptsGuard _suspendInterruptsGuard;
};


#endif /* BFFT_FRUTIL_SUSPENDSCHEDULERANDINTERRUPTSGUARD_HPP_ */
