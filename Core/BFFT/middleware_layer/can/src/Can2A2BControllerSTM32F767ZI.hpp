/*
 * Can2A2BControllerSTM32F767ZI.hpp
 *
 *  Created on: 07.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef BFFT_MIDDLEWARE_LAYER_CAN_CAN2A2BCONTROLLERSTM32F767ZI_HPP_
#define BFFT_MIDDLEWARE_LAYER_CAN_CAN2A2BCONTROLLERSTM32F767ZI_HPP_


#include "sender/ICanSender.hpp"
#include "receiver/ICanReceiver.hpp"
#include "stm32f7xx_hal.h"


class Can2A2BControllerSTM32F767ZI
		: public ICan2ASender
		, public ICan2AReceiver
		, public ICan2BSender
		, public ICan2BReceiver
{
private:
	CAN_HandleTypeDef& _canHandle;

public:
	Can2A2BControllerSTM32F767ZI(CAN_HandleTypeDef canHandle) : _canHandle(canHandle)
	{}

	void receive(const Can2AFrame& frame) override
	{
		// TODO: implement
	}

	void receive(const Can2BFrame& frame) override
	{
		// TODO: implement
	}

	void send(const Can2AFrame& frame) override
	{
		// TODO: implement
	}

	void send(const Can2BFrame& frame) override
	{
		// TODO: implement
	}
};


#endif /* BFFT_MIDDLEWARE_LAYER_CAN_NEW_CAN2A2BCONTROLLERSTM32F767ZI_HPP_ */
