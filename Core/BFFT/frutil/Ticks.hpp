/*
 * Ticks.hpp
 *
 *  Created on: 15.09.2020
 *      Author: Alex
 */

#ifndef BFFT_FRUTIL_TICKS_HPP_
#define BFFT_FRUTIL_TICKS_HPP_

#include "FreeRTOS.h"


/**
 * @fn Ticks
 * @brief Convert diverse units to ticks
 */
class Ticks
{
public:
	const TickType_t cxTicks;
	static const Ticks cMaxDelay;

	Ticks(const TickType_t cxTicks);
	static Ticks fromTicks(const TickType_t cxTicks);
	static Ticks fromMs(const uint32_t cu32ms);
};

#endif /* BFFT_FRUTIL_TICKS_HPP_ */
