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

/*modul global values*/

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

	// Currently uses bitrate of 1 Mbit/s.

	// Be aware that this example has not yet explicitly defined filters for receiving.
	// So I dont know if something can be received yet.
	// Make sure to do define filters if you want to receive the frames that you want to receive.


	if (HAL_CAN_Start(&hcan1) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_CAN_ActivateNotification(&hcan1,
			CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_RX_FIFO1_MSG_PENDING | CAN_IT_TX_MAILBOX_EMPTY) != HAL_OK)
	{
		Error_Handler();
	}


	// prepare header
	CAN_TxHeaderTypeDef header;
	// set standard id
	header.StdId = 42;
	// use standard id
	header.IDE = CAN_ID_STD;
	// this is a data frame, not a remote frame, because we have data to send
	header.RTR = CAN_RTR_DATA;
	// data length, we send eight bytes
	header.DLC = 8;
	uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint32_t txMailbox_used_to_store;



	while (true)
	{
		if (HAL_CAN_AddTxMessage(&hcan1, &header, data, &txMailbox_used_to_store) != HAL_OK)
		{
			puts("error");
			// Error_Handler();
		}
	}


	// END OF SIMPLE EXAMPLE



	/*start the can controller*/
	canController1.start();
	/*start the Interrupts*/
	canController1.activateInterrupt();


	const uint32_t cu32CAN_RxID = 0u;
	/*Filter function for the CAN*/
	CAN_FilterTypeDef s_filter_can;
	s_filter_can.FilterIdHigh = cu32CAN_RxID;
	s_filter_can.FilterIdLow = 0x0000;
	s_filter_can.FilterMaskIdHigh = 0x0000;
	s_filter_can.FilterMaskIdLow = 0x0000;
	s_filter_can.FilterFIFOAssignment = CAN_RX_FIFO0;
	s_filter_can.FilterBank = 13;
	s_filter_can.FilterMode = CAN_FILTERMODE_IDMASK;
	s_filter_can.FilterScale = CAN_FILTERSCALE_16BIT;
	s_filter_can.FilterActivation = CAN_FILTER_ENABLE;

	HAL_StatusTypeDef ret = HAL_CAN_ConfigFilter(&hcan1, &s_filter_can);
	if (ret == HAL_ERROR) throw "RxFilter can't set";

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
	halt();
	canController1.receiveFromISR();
	canController1.receiveFromISR();

}

