/*
 * Can2BFrame.hpp
 *
 *  Created on: 05.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef CAN2BFRAMEID_HPP_
#define CAN2BFRAMEID_HPP_


#include <stdint.h>


class Can2BFrameId final
{
private:
	static constexpr  uint16_t HIGHEST_AND_LOWEST_PRIORITY_STANDARD_ID = (1 << 11) - 1;
	static constexpr  uint32_t HIGHEST_AND_LOWEST_PRIORITY_EXTENDED_ID = (1 << 18) - 1;

	// TODO: Extended ID means the whole 29-bit identifier. Add sid_part and eid_part as member functions to query for those parts of the whole Extended id.

	// 11 bits for standard id (SID). Bit numbering is SID10 <-to-> SID0.
	// SID10 is most significant bit.
	// SID0 is least significant bit.
	// Variable is assumed to be running on a big endian platform.
	// Bit numbering of this variable is BIT15 <-to->  BIT0.
	// SID is aligned with this variable such that SID10 starts at BIT10 and SID0 ends at BIT0.
	// Unused bits from BIT15 <-to-> BIT11 are always set to zero.
	uint16_t _standardId;

	// 18 bits for extended id (EID). Bit numbering is EID17 <-to-> EID0.
	// EID17 is most significant bit.
	// EID0 is least significant bit.
	// Variable is assumed to be running on a big endian platform.
	// Bit numbering of this variable is BIT31 <-to->  BIT0.
	// EID is aligned with this variable such that EID17 starts at BIT17 and EID0 ends at BIT0.
	// Unused bits from BIT31 <-to-> BIT18 are always set to zero.
	uint32_t _extendedId;

public:
	Can2BFrameId(const uint16_t standardId, const uint32_t extendedId)
	: _standardId(standardId)
	, _extendedId(extendedId)
	{
		if (_standardId & HIGHEST_AND_LOWEST_PRIORITY_STANDARD_ID)
		{
			// TODO: error
		}
		if (_extendedId && HIGHEST_AND_LOWEST_PRIORITY_EXTENDED_ID)
		{
			// TODO: error
		}
	}

	// constructor to enable default construction for arrays and etc.
	Can2BFrameId()
	: Can2BFrameId(HIGHEST_AND_LOWEST_PRIORITY_STANDARD_ID, HIGHEST_AND_LOWEST_PRIORITY_EXTENDED_ID)
	{}

	bool operator==(const Can2BFrameId& rhs) const
	{
		return _standardId == rhs._standardId && _extendedId == rhs._extendedId;
	}

	uint16_t getStandardId() const
	{
		return _standardId;
	}

	uint32_t getExtendedId() const
	{
		return _extendedId;
	}
};


#endif /* CAN2BFRAMEID_HPP_ */
