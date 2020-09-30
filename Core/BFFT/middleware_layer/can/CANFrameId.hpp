/**
* @file CANFrameId.hpp
*
* @brief
* @author Alex
* @date 30.03.2020
*
**/

#ifndef CANFRAMEID_HPP_
#define CANFRAMEID_HPP_

#include <stdint.h>
//#include "stm32f7xx_hal.h"

class CANFrameId
{


public:
	const uint32_t standardId;
	const uint32_t extendedId;
	const bool isExtendedFrame;


	//full constructor
	CANFrameId(uint32_t standardId, uint32_t extendedId, bool isExtendedFrame);

	// constructor for convenience
	CANFrameId(uint32_t standardId);

	// constructor for convenience
	CANFrameId(uint32_t standardId, uint32_t extendedId);

	// used to compare to instances for equality
	bool operator== (const CANFrameId& other) const;

	// used to compare to instances for equality
	bool operator!= (const CANFrameId& other) const;
};

#endif /* CANFRAMEID_HPP_ */
