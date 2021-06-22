/**
* @class CANFrame
*
* @brief
* @author Alex
* @date 30.03.2020
*
*
*/

#include <middleware_layer/can/CANFrame.hpp>



CANFrame::CANFrame(CANFrameId id, CANPayload payload) : id(id), payload(payload)
{
	if (!payload.isValid()) throw "Invalid CAN frame payload.";
}

