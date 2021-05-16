/*
 * InverterRight.hpp
 *
 *  Created on: 16 May 2021
 *      Author: Nutzer
 */


#ifndef BFFT_DEVICE_LAYER_INVERTER_INVERTERRIGHT_HPP_
#define BFFT_DEVICE_LAYER_INVERTER_INVERTERRIGHT_HPP_

#ifdef __cplusplus

#include "Inverter.hpp"


/**
 * @fn InverterLeft
 * @brief Provide functionality for the right inverter
 */
class InverterRight : Inverter
{
public:
   const uint32_t cu32CANID{0xBBu};

public:
   InverterRight(CANController& rCanController);
   ~InverterRight() = default;

   void receive(CANFrame frame) override;
};

#endif /*__cplusplus*/

#endif /* BFFT_DEVICE_LAYER_INVERTER_INVERTERRIGHT_HPP_ */
