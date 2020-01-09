/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           Sensors.h
  * @brief          This file contains an Abstract for sensors
  *
  * @author 		Maurice Hugenschmidt
  ******************************************************************************
  * @attention
  *
  *Each new Sensor type have to include this sensor type
  *
  ******************************************************************************
  */
/* USER CODE END Header */


#ifndef SENSORS_H_
#define SENSORS_H_


/* Begin includes */

#include "stdio.h"

/* End includes */

using namespace std;

template <typename T>
class Sensors {
private:
		typedef T sensorValue;

public:
		Sensors();
		virtual ~Sensors();

		virtual typedef T getValue(){return SensorValue;};

		virtual void pickSensorData() = 0;


	#ifdef DEBUG
		void printOut(){ cout << sensorValue;};
	#endif  /* DEBUG */
};

#endif /* SENSORS_H_ */
