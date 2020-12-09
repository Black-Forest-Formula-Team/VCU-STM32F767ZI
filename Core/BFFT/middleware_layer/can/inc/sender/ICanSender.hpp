/*
 * ICanSender.hpp
 *
 *  Created on: 10.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef ICANSENDER_HPP_
#define ICANSENDER_HPP_


#include <frame/CanFrame.hpp>


template <class FRAME>
class ICanSender
{
public:
	virtual ~ICanSender() = default;
	virtual void send(const FRAME& frame) = 0;
};


using ICan2ASender = ICanSender<Can2AFrame>;
using ICan2BSender = ICanSender<Can2BFrame>;


#endif /* ICANSENDER_HPP_ */
