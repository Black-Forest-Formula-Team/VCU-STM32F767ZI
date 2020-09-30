/*
 * ICANController.hpp
 *
 *  Created on: 30.09.2020
 *      Author: Alex
 */

#ifndef BFFT_MIDDLEWARE_LAYER_CAN_ICANCONTROLLER_HPP_
#define BFFT_MIDDLEWARE_LAYER_CAN_ICANCONTROLLER_HPP_

#include <middleware_layer/can/CANFrame.hpp>
#include <middleware_layer/can/CANFrameId.hpp>
#include <middleware_layer/can/ICANSubscriber.hpp>


class ICANController
{
public:
	virtual void addSubscriber(CANFrameId id, ICANSubscriber &subscriber) = 0;
	virtual void receive(CANFrame frame) = 0;
	virtual void send(CANFrame frame) = 0;
};


#endif /* BFFT_MIDDLEWARE_LAYER_CAN_ICANCONTROLLER_HPP_ */
