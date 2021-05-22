/*
 * InverterRight.cpp
 *
 *  Created on: 16 May 2021
 *      Author: Nutzer
 */


#include "InverterRight.hpp"


/**
 * @fn InverterRight
 * @brief Constructor, sets up the base with CANController and InverterID (cu32CANID)
 * @param canController: Can controller that is used (provides functionality for CAN communication)
 */
InverterRight::InverterRight(CANController& rCanController) :
   Inverter(rCanController, CANFrameId(cu32CANID))
{
}


/**
 * @fn receive
 * @brief Receive a CAN message
 * @param frame: Defines the CAN frame that should be received
 */
void InverterRight::receive(CANFrame frame)
{
   // TODO: Implement receive routine
   puts("InverterRight: frame received");
}
