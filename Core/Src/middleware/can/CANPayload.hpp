/**
* @file CANPayload.hpp
*
* @brief
* @author Alex
* @date 30.03.2020
*
**/

#ifndef CANPAYLOAD_HPP_
#define CANPAYLOAD_HPP_

#include <stdint.h>

class CANPayload
{
public:
	union
	{
		uint8_t uint8[8];
		uint16_t uint16[4];
		uint32_t uint32[2];
	} data = {0};
	uint8_t bitLength = 0;
	bool isRemoteFrame = false;

	bool isValid() const;
};

static const CANPayload CAN_REMOTE_FRAME_PAYLOAD = CANPayload{{}, 0, true};
static const CANPayload CAN_EMPTY_DATA_FRAME_PAYLOAD = CANPayload{{}, 0, false};

#endif /* CANPAYLOAD_HPP_ */
