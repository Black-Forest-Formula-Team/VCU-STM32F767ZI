/*
 * Can2AFrameId.hpp
 *
 *  Created on: 05.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef CAN2AFRAMEID_HPP_
#define CAN2AFRAMEID_HPP_


#include <stdint.h>


class Can2AFrameId final
{
private:
	static constexpr  uint16_t HIGHEST_STANDARD_ID = (1 << 11) - 1;

	// 11 bits for standard id (SID). Bit numbering is SID10 <-to-> SID0.
	// SID10 is most significant bit.
	// SID0 is least significant bit.
	// Variable is assumed to be running on a big endian platform.
	// Bit numbering of this variable is BIT15 <-to->  BIT0.
	// SID is aligned with this variable such that SID10 starts at BIT10 and SID0 ends at BIT0.
	// Unused bits from BIT15 <-to-> BIT11 are always set to zero.
	uint16_t _standardId;

public:
	Can2AFrameId(const uint16_t standardId)
	: _standardId(standardId)
	{
		uint16_t mask_11_bits = ~HIGHEST_STANDARD_ID;

		if (_standardId & mask_11_bits)
		{
			// TODO: error
		}
	}

	// constructor to enable default construction for arrays and etc.
	Can2AFrameId()
	: Can2AFrameId(HIGHEST_STANDARD_ID)
	{}

	bool operator==(const Can2AFrameId& rhs) const
	{
	    return _standardId == rhs._standardId;
	}
	
	uint16_t getStandardId() const
	{
		return _standardId;
	}
};


#endif /* CAN2AFRAMEID_HPP_ */
