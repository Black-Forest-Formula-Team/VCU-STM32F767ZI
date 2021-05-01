/**
* @file mymain.cpp
*
* @brief
* @author Manuel Ehrhardt
* @date 05.04.2020
*
*
*/
#include <device_layer/inverter/Inverter.hpp>
#include "mymain.hpp"
#include "main.h"

/*module global values*/

CANController canController1 = CANController(hcan1);
CANFrameId canFrameIdLeftInverter = CANFrameId(0xAA);
CANFrameId canFrameIdRightInverter = CANFrameId(0xBB);


// for testing
extern "C" void halt()
{
	//while (1) {
		puts("");
	//}
}

/**
* @brief main for using cpp
* @author Manuel Ehrahrdt
* @date 05.04.2020
*
*/
void cppmain (void)
{
	// MAKE A SIMPLE CAN SEND EXAMPLE

	/*start the can controller*/
	canController1.start();
	/*start the Interrupts*/
	canController1.activateInterrupt();

	/*Filter function for the CAN*/
	CAN_FilterTypeDef s_filter_can;
	s_filter_can.FilterIdHigh = 1u<<5u;
	s_filter_can.FilterIdLow = 0x0000u;
	s_filter_can.FilterMaskIdHigh = 0x0000u;
	s_filter_can.FilterMaskIdLow = 0x0000u;
	s_filter_can.FilterFIFOAssignment = CAN_FILTER_FIFO0;
//	s_filter_can.FilterBank = 13;
	s_filter_can.FilterScale = CAN_FILTERSCALE_32BIT;
	s_filter_can.FilterActivation = CAN_FILTER_ENABLE;

	HAL_StatusTypeDef ret = HAL_CAN_ConfigFilter(&hcan1, &s_filter_can);
	if (ret == HAL_ERROR) throw "RxFilter can't set";

	InverterLeft inverterLeft = InverterLeft(canController1);
	InverterRight inverterRight = InverterRight(canController1);

	CANPayload payload;
	payload.bitLength = 64;
	payload.data.uint8[0] = 0xAAu;
	payload.data.uint8[1] = 0xABu;
	payload.data.uint8[2] = 0xACu;
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
			leftInverterFrame.payload.data.uint8[0]++;
			leftInverterFrame.payload.data.uint8[1]++;
			leftInverterFrame.payload.data.uint8[2]++;
			leftInverterFrame.payload.data.uint8[3]++;

			rightInverterFrame.payload.data.uint8[0]++;
			rightInverterFrame.payload.data.uint8[1]++;
			rightInverterFrame.payload.data.uint8[2]++;
			rightInverterFrame.payload.data.uint8[3]++;


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
	halt();
	canController1.receiveFromISR();
}

