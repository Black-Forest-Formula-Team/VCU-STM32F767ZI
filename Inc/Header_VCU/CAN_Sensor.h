/*BEGIN Header */
/**
  ******************************************************************************
  * @file           AnalogSensor.h
  * @brief          This file contains CAN-Sensors
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

#ifndef CAN_SENSOR_H_
#define CAN_SENSOR_H_

#include <Header_VCU/Sensor.h>

class CAN_Sensor: protected Sensor {

private:
	struct CANData
	{
		int CanAdress;

	};

public:

	CAN_Sensor();
	virtual ~CAN_Sensor();
	uint8_t CAN_Recieve();
};

#endif /* CAN_SENSOR_H_ */
