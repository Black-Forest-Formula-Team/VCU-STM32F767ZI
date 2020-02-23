/*BEGIN Header */
/**
  ******************************************************************************
  * @file           Sensor.h
  * @brief          This file contains all Sensors
  *
  * @author 		Maurice Hugenschmidt,Philipp Klassen
  ******************************************************************************
  * @attention
  *
  *
  *
  ******************************************************************************
  */
/*END Header */


#ifndef SENSOR_H_
#define SENSOR_H_


/* Begin includes */
#include "stdio.h"

/* End includes */

class Sensor
{

protected:

	enum SensorState
	{
		run,
		transmit,
		error,
	};

public:
	Sensor();
	~Sensor();
	float getValue();
	uint8_t getState();


};

#endif /* SENSOR_H_ */
