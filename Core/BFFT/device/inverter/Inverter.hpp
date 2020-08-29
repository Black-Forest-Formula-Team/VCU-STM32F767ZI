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
#include "middleware/can/CANController.hpp"
#include "middleware/can/CANFrameId.hpp"

class Inverter : ICANSubscriber
{
private:
	CANController& _canController;
	CANFrameId _setTargetRevolutionSpeedId;

public:
	Inverter(CANController &canController, CANFrameId setTargetRevolutionSpeedId) :
		_canController(canController),
		_setTargetRevolutionSpeedId(setTargetRevolutionSpeedId)
	{
		_canController.addSubscriber(*this, _setTargetRevolutionSpeedId);
	}
	virtual ~Inverter() = default;

	void sendTargetRevolutionSpeed(float revolutionSpeed)
	{
		CANPayload payload = CANPayload();
		memcpy(&payload.data.uint32[0], &revolutionSpeed, sizeof(payload.data.uint32[0]));
		payload.bitLength = 32;
		payload.isRemoteFrame = false;
		CANFrame frame = CANFrame(_setTargetRevolutionSpeedId, payload);
		_canController.send(frame);

	}
};


class InverterLeft : Inverter
{
public:
	InverterLeft(CANController &canController) : Inverter(canController, CANFrameId(0xAA))
	{
	}

	void update(CANFrame frame) override
	{
		puts("InverterLeft: frame received");
	}
};


class InverterRight : Inverter
{
public:
	InverterRight(CANController &canController) : Inverter(canController, CANFrameId(0xBB))
	{
	}

	void update(CANFrame frame) override
	{
		puts("InverterRight: frame received");
	}
};

#endif /*__cplusplus*/

#endif /* INVERTER_HPP_ */