/**
* @file ICANSubscriber.hpp
*
* @brief
* @author Alex
* @date 30.03.2020
*
**/

#ifndef ICANSUBSCRIBER_HPP_
#define ICANSUBSCRIBER_HPP_

#include <middleware_layer/can/CANFrame.hpp>

class ICANSubscriber
{
public:
	virtual ~ICANSubscriber() = default;
	virtual void receive(CANFrame frame) = 0;
};

#endif /* ICANSUBSCRIBER_HPP_ */
