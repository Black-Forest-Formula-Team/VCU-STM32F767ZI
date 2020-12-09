/*
 * CanPayload.hpp
 *
 *  Created on: 05.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef CANPAYLOAD_HPP_
#define CANPAYLOAD_HPP_


#include <stdint.h>

#include <frame/CanPayloadValidationCode.hpp>


class CanPayload final
{
public:
	// CAN payload is initialized and defaults to be an CAN remote frame payload.
	union {
		uint8_t uint8Array[8];
		uint16_t uint16Array[4];
		uint32_t uint32Array[2];
		uint64_t uint64;
	} data = {0};
	uint32_t bitLength = 0;
	bool isRemoteFrame = true;


	CanPayloadValidationCode checkValidity() const
	{
		// check for valid bit length
		if (bitLength < 0 || 64 < bitLength)
		{
			// Bit length is negative or longer than 64 bits.
			return CanPayloadValidationCode::INVALID_BIT_LENGTH;
		}

		// check data has only active bits (1) that are covered by bit length
		uint64_t mask = 0xFF'FF'FF'FF'FF'FF'FF'FF;
		mask = mask >> (64 - bitLength);
		mask = ~mask;
		if (mask & data.uint64)
		{
			return CanPayloadValidationCode::INVALID_BIT_LENGTH_AND_DATA;
		}

		// check that remote frame payload has no data
		if (isRemoteFrame && bitLength != 0)
		{
			// Cannot be an remote frame payload with data (bit length unequal to zero) associated with it.
			return CanPayloadValidationCode::INVALID_REMOTE_FRAME_WITH_DATA;
		}

		return CanPayloadValidationCode::VALID;
	}
};


#endif /* CANPAYLOAD_HPP_ */
