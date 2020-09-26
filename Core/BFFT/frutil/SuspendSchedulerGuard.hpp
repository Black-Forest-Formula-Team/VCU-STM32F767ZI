/*
 * SuspendSchedulerGuard.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_SUSPENDSCHEDULERGUARD_HPP_
#define BFFT_FRUTIL_SUSPENDSCHEDULERGUARD_HPP_



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


#endif /* BFFT_FRUTIL_SUSPENDSCHEDULERGUARD_HPP_ */
