/*
 * ICanSubscriberRegistry.hpp
 *
 *  Created on: 10.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef ICANSUBSCRIBERREGISTRY_HPP_
#define ICANSUBSCRIBERREGISTRY_HPP_


#include <frame/Can2AFrameId.hpp>
#include <frame/Can2BFrameId.hpp>
#include <frame/CanFrame.hpp>
#include <subscriber/ICanSubscriber.hpp>


template <class FRAME_ID, class FRAME, class SUBSCRIBER>
class ICanSubscriberRegistry
{
	virtual void addSubscriber(const FRAME_ID& id, SUBSCRIBER& subscriber) = 0;
	virtual void removeSubscriber(const SUBSCRIBER& subscriber) = 0;
	virtual void removeSubscriber(const FRAME_ID& id,const SUBSCRIBER& subscriber) = 0;
	virtual void publish(const FRAME& frame) const = 0;
};


using ICan2ASubscriberRegistry = ICanSubscriberRegistry<
		Can2AFrameId, Can2AFrame, ICan2ASubscriber>;
using ICan2BSubscriberRegistry = ICanSubscriberRegistry<
		Can2BFrameId, Can2BFrame, ICan2BSubscriber>;


#endif /* ICANSUBSCRIBERREGISTRY_HPP_ */
