/**
* @class Inverter
*
* @brief
* @author Alex
* @date 30.03.2020
*
*
*/


#include "Inverter.hpp"


/**
 * @fn Inverter
 * @brief Constructor
 * @param rCanController: Can controller that is used (provides functionality for CAN communication)
 * @param setTargetRevolutionSpeedId: CANID to set the revolution speed (=> rpm) of the target (f.e. inverter)
 */
Inverter::Inverter(CANController& rCanController, CANFrameId setTargetRevolutionSpeedId) :
   _canController(rCanController),
   _setTargetRevolutionSpeedId(setTargetRevolutionSpeedId)
{
   _canController.addSubscriber(_setTargetRevolutionSpeedId, *this);
}


/**
 * @fn sendTargetRevolutionSpeed
 * @brief Send the revolution speed (=> rpm) to the target (f.e. inverter)
 * @param cfRevolutionSpeed: Revolution speed to be send to the target
 */
void Inverter::sendTargetRevolutionSpeed(const float cfRevolutionSpeed)
{
   CANPayload payload;

   memcpy(&payload.data.uint32[0u], &cfRevolutionSpeed, sizeof(payload.data.uint32[0u]));

   payload.bitLength = 32u;
   payload.isRemoteFrame = false;

   CANFrame frame(_setTargetRevolutionSpeedId, payload);

   _canController.send(frame);
}
