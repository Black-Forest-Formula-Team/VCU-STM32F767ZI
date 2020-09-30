/**
* @file CANFrame.hpp
*
* @brief
* @author Alex
* @date 30.03.2020
*
**/

#ifndef CANFRAME_HPP_
#define CANFRAME_HPP_

#include <middleware_layer/can/CANFrameId.hpp>
#include <middleware_layer/can/CANPayload.hpp>

class CANFrame
{
private:
public:
	const CANFrameId id;
	/*no const use for the send HAL_Function*/
	CANPayload payload;

	CANFrame(CANFrameId id, CANPayload payload);

};

#endif /* CANFRAME_HPP_ */
