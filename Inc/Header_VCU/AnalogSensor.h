/*BEGIN Header */
/**
  ******************************************************************************
  * @file           AnalogSensor.h
  * @brief          This file contains AnalogSensors
  *
  * @author 		Philipp Klassen
  ******************************************************************************
  * @attention
  *
  *
  *
  ******************************************************************************
  */
/*END Header */


#ifndef ANALOGSENSOR_H_
#define ANALOGSENSOR_H_

#include <Header_VCU/Sensor.h>

class AnalogSensor: protected Sensor {

protected:

	int SensorPort;
	float Sensorblabla;

	struct ADCData
	{
		int ADCadress;
		float ADCfactor;

	};

public:
	AnalogSensor();
	virtual ~AnalogSensor();
	uint8_t ADCStart();
	uint8_t ADConversation();
};

#endif /* ANALOGSENSOR_H_ */
