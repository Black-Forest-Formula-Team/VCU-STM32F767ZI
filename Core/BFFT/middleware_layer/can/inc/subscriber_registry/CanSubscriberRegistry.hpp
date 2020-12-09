/*
 * CanSubscriberRegistry.hpp
 *
 *  Created on: 10.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef CANSUBSCRIBERREGISTRY_HPP_
#define CANSUBSCRIBERREGISTRY_HPP_


#include <stddef.h>
#include <array>

#include <subscriber_registry/ICanSubscriberRegistry.hpp>


template <
class I_CAN_SUBSCRIBER_REGISTRY,
class FRAME_ID,
class FRAME,
class SUBSCRIBER,
size_t MAX_NUM_SUBSCRIBERS
>
class CanSubscriberRegistry : public I_CAN_SUBSCRIBER_REGISTRY
{
private:
	size_t _freeIndex = 0;
	std::array<FRAME_ID, MAX_NUM_SUBSCRIBERS> _ids;
	std::array<SUBSCRIBER*, MAX_NUM_SUBSCRIBERS> _subscribers;

public:
	void addSubscriber(const FRAME_ID& id, SUBSCRIBER& subscriber) override
	{
		if (_freeIndex == MAX_NUM_SUBSCRIBERS)
		{
			// TODO: error
		}

		// add subscriber
		_subscribers[_freeIndex] = &subscriber;
		_ids[_freeIndex] = id;

		// find next free spot
		for (size_t i = _freeIndex; i <= MAX_NUM_SUBSCRIBERS; ++i)
		{
			if (_subscribers[i] == nullptr || i == MAX_NUM_SUBSCRIBERS)
			{
				_freeIndex = i;
				break;
			}
		}
	}

	void removeSubscriber(const SUBSCRIBER& subscriber) override
	{
		for (size_t i = 0; i < MAX_NUM_SUBSCRIBERS; ++i)
		{
			if (_subscribers[i] == &subscriber)
			{
				// remove subscriber
				_subscribers[i] = nullptr;

				// update free spot
				if (i < _freeIndex)
				{
					_freeIndex = i;
				}
			}
		}
	}

	void removeSubscriber(const FRAME_ID& id, const SUBSCRIBER& subscriber) override
	{
		for (size_t i = 0; i < MAX_NUM_SUBSCRIBERS; ++i)
		{
			if (_subscribers[i] == &subscriber && _ids[i] == id)
			{
				// remove subscriber
				_subscribers[i] = nullptr;

				// update free spot
				if (i < _freeIndex)
				{
					_freeIndex = i;
				}
			}
		}
	}

	void publish(const FRAME& frame) const override
	{
		const FRAME_ID ID = frame.getId();

		for (size_t i = 0; i < MAX_NUM_SUBSCRIBERS; ++i)
		{
			if (_subscribers[i] != nullptr && _ids[i] == ID)
			{
				_subscribers[i]->onPublish(frame);
			}
		}
	}
};


template <size_t MAX_NUM_SUBSCRIBERS>
using Can2ASubscriberRegistry = CanSubscriberRegistry<
		ICan2ASubscriberRegistry,
		Can2AFrameId,
		Can2AFrame,
		ICan2ASubscriber,
		MAX_NUM_SUBSCRIBERS>;

template <size_t MAX_NUM_SUBSCRIBERS>
using Can2BSubscriberRegistry = CanSubscriberRegistry<
		ICan2BSubscriberRegistry,
		Can2BFrameId,
		Can2BFrame,
		ICan2BSubscriber,
		MAX_NUM_SUBSCRIBERS>;


#endif /* CANSUBSCRIBERREGISTRY_HPP_ */
