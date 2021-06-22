/*
 * Ticks.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_TICKS_HPP_
#define BFFT_FRUTIL_TICKS_HPP_


class Ticks
{
public:
	static const Ticks Max_Delay;

	const TickType_t ticks;

	Ticks(TickType_t ticks): ticks(ticks)
	{}

	static Ticks fromTicks(TickType_t ticks)
	{
		return Ticks(ticks);
	}

	static Ticks fromMs(unsigned long ms)
	{
		// TODO: check for overflow
		return Ticks(portTICK_RATE_MS * ms);
	}
};

// initialize static const member
//const Ticks Ticks::Max_Delay = Ticks(0);


#endif /* BFFT_FRUTIL_TICKS_HPP_ */
