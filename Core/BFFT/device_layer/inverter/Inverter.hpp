/**
* @file Inverter.hpp
*
* @brief
* @author Alex
* @date 30.03.2020
*
**/

#ifndef INVERTER_HPP_
#define INVERTER_HPP_

#ifdef __cplusplus

#include <stdio.h>
#include <cstring>
#include <middleware_layer/can/CANController.hpp>
#include <middleware_layer/can/CANFrameId.hpp>


/**
 * @fn Inverter
 * @brief Provides basic functionality for both inverters (right and left)
 */
class Inverter : ICANSubscriber
{
private:
	CANController& _canController;
	CANFrameId _setTargetRevolutionSpeedId;

public:
	Inverter(CANController& rCanController, CANFrameId setTargetRevolutionSpeedId);
	virtual ~Inverter() = default;

	void sendTargetRevolutionSpeed(const float cfRevolutionSpeed);
};

#endif /*__cplusplus*/

#endif /* INVERTER_HPP_ */
