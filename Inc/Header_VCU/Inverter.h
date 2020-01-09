/*BEGIN Header */
/**
  ******************************************************************************
  * @file           Inverter.h.h
  * @brief
  *
  * @author 		Maurice Hugenschmidt, Alexander Sperka
  ******************************************************************************
  * @attention
  *
  *
  *
  ******************************************************************************
  */
/*END Header */

#ifndef INVERTER_H_
#define INVERTER_H_


/* Begin includes */

#include "stdio.h"
#include "stm32f7xx_hal_can.h"

/* End includes */

using namespace std;

class Inverter {
private:
	CAN_HandleTypeDef canInterface;
	uint8_t deviceAddress;
	uint16_t rpm = 0;


	float torque = 0;
	float motorTemp, inverterTemp;

public:
		Inverter(CAN_HandleTypeDef* canInteface, uint8_t deviceAddress);
		int Init();
		virtual ~Inverter();

		float getTorque();
		uint8_t setTorque(double torque);


		float getMotorTemp();
		float getInverterTemp();

		uint16_t getRPM();


};

#endif /* INVERTER_H_ *
