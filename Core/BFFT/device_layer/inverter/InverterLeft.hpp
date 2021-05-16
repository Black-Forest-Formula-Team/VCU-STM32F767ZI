/*
 * InverterLeft.hpp
 *
 *  Created on: 16 May 2021
 *      Author: Nutzer
 */

#ifndef BFFT_DEVICE_LAYER_INVERTER_INVERTERLEFT_HPP_
#define BFFT_DEVICE_LAYER_INVERTER_INVERTERLEFT_HPP_

#ifdef __cplusplus

#include "Inverter.hpp"


/**
 * @fn InverterLeft
 * @brief Provide functionality for the left inverter
 */
class InverterLeft : Inverter
{
public:
   const uint32_t cu32CANID{0xAAu};

public:
   InverterLeft(CANController& rCanController);
   ~InverterLeft() = default;

   void receive(CANFrame frame) override;
};

#endif /*__cplusplus*/

#endif /* BFFT_DEVICE_LAYER_INVERTER_INVERTERLEFT_HPP_ */
