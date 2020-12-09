/*
 * ICanReceiver.hpp
 *
 *  Created on: 10.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef ICANRECEIVER_HPP_
#define ICANRECEIVER_HPP_


#include <frame/CanFrame.hpp>


template <class FRAME>
class ICanReceiver
{
public:
	virtual ~ICanReceiver() = default;
	virtual void receive(const FRAME& frame) = 0;
};


using ICan2AReceiver = ICanReceiver<Can2AFrame>;
using ICan2BReceiver = ICanReceiver<Can2BFrame>;


#endif /* ICANRECEIVER_HPP_ */
