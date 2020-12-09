/*
 * CanPayloadValidationCode.hpp
 *
 *  Created on: 06.11.2020
 *      Author: Alexander Bierenstiel
 */

#ifndef CANPAYLOADVALIDATIONCODE_HPP_
#define CANPAYLOADVALIDATIONCODE_HPP_


enum class CanPayloadValidationCode
{
	VALID,
	INVALID_REMOTE_FRAME_WITH_DATA,
	INVALID_BIT_LENGTH,
	INVALID_BIT_LENGTH_AND_DATA
};


#endif /* CANPAYLOADVALIDATIONCODE_HPP_ */
