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
        Compiler          :  GNU Tools for   STM32 (9-2020-q2 update)
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

#ifndef TESTCAN_HPP
#define TESTCAN_HPP

typedef enum
{
   TEST_INIT,
   TEST_CHANGE_DATA,
   TEST_IF_BUTTON_PRESSED,
   TEST_IF_BUTTON_RELEASED,
   TEST_ERROR,
} eTEST_STATES;



#ifdef __cplusplus
extern "C" {
#endif
   void vtestCAN (void);
   void CAN1_irq_receive();

#ifdef __cplusplus
}
#endif

#endif /* INC_MYMAIN_HPP_ */
