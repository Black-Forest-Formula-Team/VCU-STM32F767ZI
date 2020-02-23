/**
  ******************************************************************************
  * @file         : Sensor.cpp
  * @brief        : This file provides PedalSensors and the Initialization
  *
  * @author		  :Philipp Klassen
  ******************************************************************************
  * @attention
  *
  *
  *
  ******************************************************************************
  */
#ifndef CLASS_VCU_PEDALSENSOR_H_
#define CLASS_VCU_PEDALSENSOR_H_

#include <Header_VCU/AnalogSensor.h>

class PedalSensor: private AnalogSensor {

private:
	uint32_t pedalAngle;
public:
	PedalSensor();
	virtual ~PedalSensor();
	 int32_t getPedalSensorData();
};

#endif /* CLASS_VCU_PEDALSENSOR_H_ */
