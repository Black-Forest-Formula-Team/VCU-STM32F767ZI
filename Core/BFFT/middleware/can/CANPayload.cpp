/**
* @class CANPayload
*
* @brief
* @author Alex
* @date 30.03.2020
*
*
*/

#include "CANPayload.hpp"

bool CANPayload::isValid() const
{
	if (isRemoteFrame && bitLength) return false;
	if (bitLength > 64) return false;
	if (bitLength <= 32)
	{
		if (data.uint32[1]) return false;
		if (data.uint32[0] >> bitLength) return false;
	}
	else if (data.uint32[1] >> (bitLength - 32)) return false;
	return true;
}
