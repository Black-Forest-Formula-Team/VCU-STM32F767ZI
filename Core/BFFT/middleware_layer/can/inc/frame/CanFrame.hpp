/*
 * CanFrame.hpp
 *
 *  Created on: 10.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef CANFRAME_HPP_
#define CANFRAME_HPP_


#include <frame/Can2AFrameId.hpp>
#include <frame/Can2BFrameId.hpp>
#include <frame/CanPayloadValidated.hpp>


template <class FRAME_ID>
class CanFrame final
{
private:
	FRAME_ID _id;
	CanPayloadValidated _payload;

public:
	CanFrame(const FRAME_ID& id, const CanPayloadValidated& payload)
	: _id(id)
	, _payload(payload)
	{}

	// constructor to enable default construction for arrays and etc.
	CanFrame()
	: CanFrame(FRAME_ID(), CanPayloadValidated())
	{}

	FRAME_ID getId() const
	{
		return _id;
	}

	CanPayloadValidated getPayload() const
	{
		return _payload;
	}
};


using Can2AFrame = CanFrame<Can2AFrameId>;
using Can2BFrame = CanFrame<Can2BFrameId>;


#endif /* CANFRAME_HPP_ */
