/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           VehicleModel.h
  * @brief          This file contains the Vehicle Model class
  *
  * @author 		Alexander Sperka
  ******************************************************************************
  * @attention
  * Last configured: 13.12.2019
  * Class is used for all vehicle related calculations - Torque (later with vectoring), Derating, Look up table for Battery cells, Heading and speed of car, ...
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#ifndef VEHICLEMODEL_H_
#define VEHICLEMODEL_H_

class VehicleModel {
	public:
		VehicleModel();
		virtual ~VehicleModel();
		float calculateTorque();
		float calculateTorqueVectoring();
		float checkDerating();
		float calculateLookUpTableBattery();

	private:
		float torque;
		bool derating;
		unsigned short int lookupBattery[1000];
		//... TBD
};

#endif /* VEHICLEMODEL_H_ */
