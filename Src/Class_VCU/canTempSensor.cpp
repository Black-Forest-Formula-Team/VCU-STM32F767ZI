/**
  ******************************************************************************
  * @file         : canTempSensor.cpp
  * @brief        : This file provides all Sensors and the initialization
  *
  * @author		  : Maurice Hugenschmidt
  ******************************************************************************
  * @attention
  * TBD
  *
  *
  ******************************************************************************
  */

/* Begin includes */
#include "Header_VCU/canTempSensor.h"
/* End includes */

/**
* @brief Empty constructor
*/
canTempSensor::canTempSensor(){};

canTempSensor::~canTempSensor(){};

/**
* @brief Constructor and initialization
* @param canInterface as reference of type CAN
* @param deviceAddress as address of the CAN device
*/
canTempSensor::canTempSensor(CAN_HandleTypeDef* canInterface, uint8_t deviceAddress)
{
	this->init(canInteface, deviceAddress);
}


/**
* @brief Initialization of the Sensors
* @param canInterface as reference of type CAN
* @param deviceAddress as address of the CAN device
* @return 0 when Successful
*/
canTempSensor::init(CAN_HandleTypeDef* canInterface, uint8_t deviceAddress)
{
	this->canInterface = canInterface;
	this->deviceAddress = deviceAddress;

	return 0;
}

/**
* @brief Pick data from the Sensor
* @return 0 when Successful
*/
canTempSensor::pickSensorData()
{

	return 0;
}

/**
* @brief Function to get the temperature as a float
* @return The temperature value
*/
float canTempSensor::getTemperature()
{
	return temp;
}


