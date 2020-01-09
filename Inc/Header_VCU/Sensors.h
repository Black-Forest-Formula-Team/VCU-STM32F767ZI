/*BEGIN Header */
/**
  ******************************************************************************
  * @file           Sensors.h
  * @brief          This file contains all Sensors
  *
  * @author 		Maurice Hugenschmidt
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
	Sensors();
	~Sensors();


public:
	canTempSensor coolantTemp;


};

#endif /* SENSORS_H_ */
