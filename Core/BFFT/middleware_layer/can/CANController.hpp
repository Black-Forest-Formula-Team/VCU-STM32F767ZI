/**
* @file CANController.hpp
*
* @brief
* @author Alex
* @date 30.03.2020
*
**/

#ifndef CANCONTROLLER_HPP_
#define CANCONTROLLER_HPP_

#include <middleware_layer/can/CANControllerBase.hpp>
#include <middleware_layer/can/CANHandle.hpp>


class CANController : public CANControllerBase
{
	CANHandle &_canHandle;

public:
	CANController(CANHandle &canHandle);

	void send(CANFrame frame) override;

	void receiveFromISR(void);
	void start(void);
	void activateInterrupt (void);
	void deactivateInterrupt (void);
};


#endif /* CANCONTROLLER_HPP_ */
