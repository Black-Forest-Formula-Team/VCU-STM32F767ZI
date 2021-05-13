/*
 * Ticks.cpp
 *
 *  Created on: 9 May 2021
 *      Author: Nutzer
 */

#include "Ticks.hpp"


/**
 * @fn cxMaxDelay
 * @brief Defines the maximal delay that should be applied to a thread
 */
const Ticks Ticks::cMaxDelay = Ticks(static_cast<TickType_t>(1000u/portTICK_RATE_MS)); // TODO: Max delay has to be defined appropriately


/**
 * @fn Ticks
 * @brief Constructor
 */
Ticks::Ticks(const TickType_t cxTicks): cxTicks(cxTicks)
{
}


/**
 * @fn Ticks
 * @brief Return object of Ticks from ticks
 * @param cxTicks: Defines the length of delay in ticks
 */
Ticks Ticks::fromTicks(const TickType_t cxTicks)
{
   return Ticks(cxTicks);
}


/**
 * @fn Ticks
 * @brief Convert time into ticks and return an object of type Ticks
 * @param cu32ms: Defines the length of delay in ms
 */
Ticks Ticks::fromMs(const uint32_t cu32ms)
{
   return Ticks(static_cast<TickType_t>(cu32ms/portTICK_RATE_MS));
}
