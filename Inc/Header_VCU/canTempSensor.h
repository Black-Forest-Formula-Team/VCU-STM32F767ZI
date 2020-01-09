/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           TempSensor.h
  * @brief          This file Provides a Temperature Sensor Class for CAN
  *
  * @author 		Maurice Hugenschmidt
  ******************************************************************************
  * @attention
  *
  *This Sensor class can recive data only from CAN
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef canTempSensor_H_
#define canTempSensor_H_

/* Begin includes */
#include "stdio.h"
#include "stm32f7xx_hal_can.h"
/* End includes */

using namespace std;

class canTempSensor{

private:
	CAN_HandleTypeDef canInterface;
	uint8_t deviceAddress;


public:
	canTempSensor(CAN_HandleTypeDef* canInteface, uint8_t deviceAddress);
	~canTempSensor();

	float getTemperature();

};

#endif /* canTempSensor_H_ */
