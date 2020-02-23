/*
 * IMU_Sensor.h
 *
 *  Created on: 23.02.2020
 *      Author: Phil
 */

#ifndef IMU_SENSOR_H_
#define IMU_SENSOR_H_

#include <Header_VCU/CAN_Sensor.h>

class IMU_Sensor: protected CAN_Sensor {
private:
	struct IMUData
	{
		int Position;
		int G_Force;
	};
public:
	IMU_Sensor();
	virtual ~IMU_Sensor();
	uint8_t getIMUSensorData();
};

#endif /* IMU_SENSOR_H_ */
