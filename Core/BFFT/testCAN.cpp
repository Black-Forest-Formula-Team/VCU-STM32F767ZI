/**
  Just a simple Task for testing CAN communication.
  @Company
  	  BFFT
  @File Name
    testCAN.cpp
  @Summary
    This is an example task that sends CAN Inverter Frames.
  @Description
    This source file sends Inverter CAN frames when the on board button is pressed
    Generation Information :
        Product Revision  :  STM32F7
        Device            :  STM32F767ZI
    The following file are tested against the following:
        Compiler          :  GNU Tools for 	STM32 (9-2020-q2 update)
        MPLAB             :  STM32CUBE IDE 1.6.0
*/

/*
    (c) 2021 Black Forest Formula Team (BFFT)
    THIS SOFTWARE IS SUPPLIED BY BFFT "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.
    IN NO EVENT WILL BFFT BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF BFFT
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, BFFT'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO BFFT FOR THIS
    SOFTWARE.
*/

#include <device_layer/inverter/Inverter.hpp>
#include <testCAN.hpp>
#include "main.h"
/******************************************************************************************************************/
/* Definitions Section*/
/******************************************************************************************************************/

/******************************************************************************************************************/
/*Global Variables*/
/******************************************************************************************************************/

CANController canController1       = CANController(hcan1);
InverterLeft  inverterLeft         = InverterLeft(canController1);
InverterRight inverterRight        = InverterRight(canController1);
CANFrameId canFrameIdLeftInverter  = CANFrameId(0xAA);
CANFrameId canFrameIdRightInverter = CANFrameId(0xbb);
CANPayload payload;
CANFrame leftInverterFrame  = CANFrame(canFrameIdLeftInverter, payload);
CANFrame rightInverterFrame = CANFrame(canFrameIdRightInverter, payload);

eTEST_STATES eMachineState = TEST_INIT;
/******************************************************************************************************************/

/*******************************************************************************************************************
Routine Name	: vtestCAN
Date Created	: 13-05-2021
Author			: Adian Shubbar
Description 	: Test CAN
Arguments		: void
Returns  		: void
Called by		: StartDefaultTask in main
Notes:-
1) Error state is not yet defined or implemented.s
*******************************************************************************************************************/
void vtestCAN (void)
{

	switch(eMachineState)
	{
		case TEST_INIT:
			/*start the can controller*/
			canController1.start();
			/*start the Interrupts*/
			canController1.activateInterrupt();
			/*Initializing the payload to be transmitted*/
			payload.bitLength     = 64u;
			payload.isRemoteFrame = false;
			payload.data.uint8[0] = 0x11u ;
		    payload.data.uint8[1] = 0x22u;
		    payload.data.uint8[2] = 0x33u;
		    payload.data.uint8[3] = 0x44u;
		    payload.data.uint8[4] = 0x55u;
		    payload.data.uint8[5] = 0x66u;
		    payload.data.uint8[6] = 0x77u;
		    payload.data.uint8[7] = 0x88u;

			eMachineState=TEST_IF_BUTTON_PRESSED;
			break;

		case TEST_IF_BUTTON_PRESSED:
		   if(HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin))
		   {
		      HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
            /*CAN send*/
            canController1.send(leftInverterFrame);
            canController1.send(rightInverterFrame);
            eMachineState=TEST_IF_BUTTON_RELEASED;
		   }
		   else
		   {
		      eMachineState = TEST_IF_BUTTON_PRESSED;
		   }
		   break;

		case TEST_IF_BUTTON_RELEASED:
		   if(HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin))
		   {
		      eMachineState = TEST_IF_BUTTON_RELEASED;
		   }
		   else
		   {
		      eMachineState = TEST_CHANGE_DATA;
		   }
		   break;

		case TEST_CHANGE_DATA:
		   payload.data.uint8[0]++;
		   payload.data.uint8[1]++;
		   payload.data.uint8[2]++;
		   payload.data.uint8[3]++;
		   payload.data.uint8[4]++;
		   payload.data.uint8[5]++;
		   payload.data.uint8[6]++;
		   payload.data.uint8[7]++;
		   eMachineState = TEST_IF_BUTTON_PRESSED;
		   break;

		case TEST_ERROR:
		default:
			while(1)
			{
				;
			}
			break;

	}


}


/*******************************************************************************************************************
Routine Name	: CAN1_irq_receive
Date Created	: 19-05-2021
Author			: Manuel Erhadt
Description 	: CAN recieve callback function.
Arguments		: void
Returns  		: void
Called by		: Not used yet (checked call graph)
*******************************************************************************************************************/
void CAN1_irq_receive()
{
	canController1.receiveFromISR();
}

/*******************************************************************************************************************
Routine Name	: CAN1_irq_receive
Date Created	: 19-05-2021
Author			: Manuel Erhadt
Description 	: CAN recieve callback function.
Arguments		: void
Returns  		: void
Called by		: Not used yet (checked call graph)
*******************************************************************************************************************/
extern "C" void halt()
{
	//while (1) {
		puts("");
	//}
}
