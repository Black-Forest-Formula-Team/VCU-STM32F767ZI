/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           canTempSensor.h
  * @brief          This file Provides a Temperature Sensor Class for CAN
  *
  * @author 		Maurice Hugenschmidt
  ******************************************************************************
  * @attention
  *
  *This Sensor class can receive data only from CAN
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef canTempSensor_H_
#define canTempSensor_H_

/* Begin includes */
#include "stdio.h"
#include "main.h"
/* End includes */

using namespace std;

class canTempSensor{

private:
	CAN_HandleTypeDef* canInterface;
	uint8_t deviceAddress;
	float temp;


public:
	canTempSensor();
	canTempSensor(CAN_HandleTypeDef* canInterface, uint8_t deviceAddress);
	~canTempSensor();

	uint8_t init(CAN_HandleTypeDef* canInterface, uint8_t deviceAddress);
	uint8_t pickSensorData();

	float getTemperature();

};

#endif /* canTempSensor_H_ */
