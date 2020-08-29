/**
* @class CANFrameId
*
* @brief
* @author Alex
* @date 30.03.2020
*
*
*/
#include "CANFrameId.hpp"

CANFrameId::CANFrameId(uint32_t standardId, uint32_t extendedId, bool isExtendedFrame) :
	standardId(standardId), extendedId(extendedId), isExtendedFrame(isExtendedFrame)
{
	// check standard id
	if (standardId & ~0x7FF) throw "Not an 11 bit CAN standard id.";
	// check extended id
	if (!isExtendedFrame && extendedId) throw "CAN extended id is not used but is not zero.";
	if (isExtendedFrame && (extendedId & ~0x3FF)) throw "Not an 18 bit CAN extended id.";
}


CANFrameId::CANFrameId(uint32_t standardId) : CANFrameId(standardId, 0, false)
{
	// do nothing here
}


CANFrameId::CANFrameId(uint32_t standardId, uint32_t extendedId) : CANFrameId(standardId, extendedId, true)
{
	// do nothing here
}


bool CANFrameId::operator== (const CANFrameId& other) const
{
	return (standardId == other.standardId &&
			extendedId == other.extendedId &&
			isExtendedFrame == other.isExtendedFrame);
}


bool CANFrameId::operator!= (const CANFrameId& other) const
{
	return operator==(other);
}
