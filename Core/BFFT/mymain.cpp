/**
* @file mymain.cpp
*
* @brief
* @author Manuel Ehrhardt
* @date 05.04.2020
*
*
*/
#include "mymain.hpp"
#include "main.h"
#include <device/inverter/Inverter.hpp>

/*modul global values*/

CANController canController1 = CANController(hcan1);
CANFrameId canFrameIdLeftInverter = CANFrameId(0xAA);
CANFrameId canFrameIdRightInverter = CANFrameId(0xBB);


/**
* @brief main for using cpp
* @author Manuel Ehrahrdt
* @date 05.04.2020
*
*/
void cppmain (void)
{

	/*Filter function for the CAN*/

	CAN_FilterTypeDef s_filter_can;

	s_filter_can.FilterMaskIdHigh = 0x0000;
	s_filter_can.FilterIdLow = 0x0000;
	s_filter_can.FilterMaskIdHigh = 0x0000;
	s_filter_can.FilterMaskIdLow = 0x0000;
	s_filter_can.FilterFIFOAssignment = CAN_RX_FIFO0;
	s_filter_can.FilterBank = 13;
	s_filter_can.FilterMode = CAN_FILTERMODE_IDMASK;
	s_filter_can.FilterScale = CAN_FILTERSCALE_16BIT;
	s_filter_can.FilterActivation = CAN_FILTER_ENABLE;

	if (HAL_CAN_ConfigFilter(&hcan1, &s_filter_can)) throw "RxFilter can't set";



	/*start the can controller*/
	canController1.start();
	/*start the Interrupts*/
	canController1.activateInterrupt();






	InverterLeft inverterLeft = InverterLeft(canController1);
	InverterRight inverterRight = InverterRight(canController1);

	CANPayload payload;
	payload.bitLength = 8;
	payload.data.uint8[0] = 0xAA;
	payload.isRemoteFrame = false;
	CANFrame leftInverterFrame = CANFrame(canFrameIdLeftInverter, payload);
	CANFrame rightInverterFrame = CANFrame(canFrameIdRightInverter, payload);





	uint8_t u8_pin_state = 0;
	uint8_t u8_last_pin_state = 0;


	while(1)
	{	/*read user-button*/
		u8_pin_state = HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin);

		if( u8_pin_state == 1 && u8_last_pin_state == 0)
		{	/*button is push*/
			/*toggle led*/
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			u8_last_pin_state = 1;
			/*CAN send*/
			canController1.send(leftInverterFrame);
			canController1.send(rightInverterFrame);

		}
		else if (u8_pin_state == 0 && u8_last_pin_state == 1)
		{
			u8_last_pin_state = 0;
		}
	}





}


/**
* @brief handle the IRQ for cpp
* @author Manuel Ehrhardt
* @date 05.04.2020
*
*/
void CAN1_irq_receive()
{
	canController1.receiveFromISR();
	canController1.receiveFromISR();

}

