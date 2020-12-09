/*
 * AbstractCanSubscriber.hpp
 *
 *  Created on: 10.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef ICANSUBSCRIBER_HPP_
#define ICANSUBSCRIBER_HPP_


#include <frame/Can2AFrameId.hpp>
#include <frame/Can2BFrameId.hpp>
#include <frame/CanFrame.hpp>


template <class FRAME_ID, class FRAME>
class ICanSubscriber
{
public:
	virtual ~ICanSubscriber() = default;
	virtual void onPublish(const FRAME& frame) = 0;
};


using ICan2ASubscriber = ICanSubscriber<Can2AFrameId, Can2AFrame>;
using ICan2BSubscriber = ICanSubscriber<Can2BFrameId, Can2BFrame>;


#endif /* ICANSUBSCRIBER_HPP_ */
