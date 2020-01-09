/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           Tempsensor.h
  * @brief          This file Provides a Temperature Sensor Class
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

#ifndef TempSensor_H_
#define TempSensor_H_

template <typename T>
class TempSensor:Sensor {

private:
	void calculateTempertaure();

public:
	Tempsensor();



};

#endif /* TempSensor_H_ */
