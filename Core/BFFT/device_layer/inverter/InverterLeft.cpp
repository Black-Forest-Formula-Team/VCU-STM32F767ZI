/*
 * InverterLeft.cpp
 *
 *  Created on: 16 May 2021
 *      Author: Nutzer
 */


#include "InverterLeft.hpp"

/**
 * @fn InverterLeft
 * @brief Constructor, sets up the base with CANController and InverterID (cu32CANID)
 * @param canController: Can controller that is used (provides functionality for CAN communication)
 */
InverterLeft::InverterLeft(CANController& rCanController) :
   Inverter(rCanController, CANFrameId(cu32CANID))
{
}


/**
 * @fn receive
 * @brief Receive a CAN message
 * @param frame: Defines the CAN frame that should be received
 */
void InverterLeft::receive(CANFrame frame)
{
   // TODO: implement receive routine
   puts("InverterLeft: frame received");
}
