/*
 * test.cpp
 *
 * This file is for experimenting purposes with code that is being written. This file forces the included header files to be compiled. It can be safely deleted.
 *
 *  Created on: 11.08.2020
 *      Author: Alex
 */

#include "sensor_data.hpp"

void test()
{
	SensorDataBuffer sensorDataBuffer;
	SensorDataAccessGuard writeAccess = sensorDataBuffer.getAccessGuard();
	InverterLeft_Current current = InverterLeft_Current(Current_Ampere_Float(0.5));
	sensorDataBuffer.getAccessGuard().sensorData.inverterLeft_current = current;
	current = sensorDataBuffer.getAccessGuard().sensorData.inverterLeft_current = current;
}
