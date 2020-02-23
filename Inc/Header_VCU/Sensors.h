/*BEGIN Header */
/**
  ******************************************************************************
  * @file           Sensors.h
  * @brief          This file contains all Sensors
  *
  * @author 		Philipp Klassen
  ******************************************************************************
  * @attention
  *
  *This Header contains all Sensors
  *
  ******************************************************************************
  */
/*END Header */


#ifndef SENSORS_H_
#define SENSORS_H_


/* Begin includes */
#include "stdio.h"
#include "canTempSensor.h"
/* End includes */

class Sensors
{

private:

	enum SensorState
	{
		run,
		transmit,
		error,
	};

public:
	Sensors();
	~Sensors();
	float getValue();
	uint8_t getState();


};

#endif /* SENSORS_H_ */
