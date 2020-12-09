/*
 * CanPayloadValidated.hpp
 *
 *  Created on: 06.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef CANPAYLOADVALIDATED_HPP_
#define CANPAYLOADVALIDATED_HPP_


#include <frame/CanPayload.hpp>
#include <frame/CanPayloadValidationCode.hpp>


class CanPayloadValidated final
{
private:
	CanPayload _payload;

public:
	CanPayloadValidated(const CanPayload& payload)
	: _payload(payload)
	{
		if (_payload.checkValidity() != CanPayloadValidationCode::VALID)
		{
			// TODO: error
		}
	}

	// constructor to enable default construction for arrays and etc.
	CanPayloadValidated()
	: CanPayloadValidated(CanPayload())
	{}

	CanPayload getPayload() const
	{
		return _payload;
	}
};


#endif /* CANPAYLOADVALIDATED_HPP_ */
