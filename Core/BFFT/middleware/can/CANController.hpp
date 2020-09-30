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

#include <vector>
#include "ICANSubscriber.hpp"
#include "CANHandle.hpp"

class CANController
{
	CANHandle &_canHandle;
	std::vector<ICANSubscriber*> _canSubscribers;
	std::vector<CANFrameId> _canFrameIds;

public:
	CANController(CANHandle &canHandle);

	void addSubscriber(ICANSubscriber &subscriber, CANFrameId id);

	void receive(CANFrame frame);

	void receiveFromISR(void);

	void send(CANFrame frame);

	void start(void);

	void activateInterrupt (void);

	void deactivateInterrupt (void);

};

#endif /* CANCONTROLLER_HPP_ */
