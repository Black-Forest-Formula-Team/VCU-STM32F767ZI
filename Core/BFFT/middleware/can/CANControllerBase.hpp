/*
 * CANControllerBase.hpp
 *
 *  Created on: 30.09.2020
 *      Author: Alex
 */

#ifndef BFFT_MIDDLEWARE_CAN_CANCONTROLLERBASE_HPP_
#define BFFT_MIDDLEWARE_CAN_CANCONTROLLERBASE_HPP_

#include <ICANController.hpp>
#include <vector>


class CANControllerBase : public ICANController
{
	std::vector<CANFrameId> _canFrameIds;
	std::vector<ICANSubscriber*> _canSubscribers;

public:
	void addSubscriber(CANFrameId id, ICANSubscriber &subscriber) override
	{
		_canFrameIds.push_back(id);
		_canSubscribers.push_back(&subscriber);
	}

	void receive(CANFrame frame) override
	{
		// update each subscriber that listens to the same frame id as the id of the given frame
		for (auto it = _canFrameIds.begin(); it != _canFrameIds.end(); ++it)
		{
			if (frame.id == *it)
			{
				const int index = it - _canFrameIds.begin();
				ICANSubscriber *subscriber = _canSubscribers[index];
				subscriber->receive(frame);
			}
		}
	}
};


#endif /* BFFT_MIDDLEWARE_CAN_CANCONTROLLERBASE_HPP_ */
