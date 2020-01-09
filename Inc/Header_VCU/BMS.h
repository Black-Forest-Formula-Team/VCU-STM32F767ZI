/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           BMS.h
  * @brief          This file contains the Battery Management System class
  *
  * @author 		Alexander Sperka
  ******************************************************************************
  * @attention
  * Last configured: 13.12.2019
  * To calculate the available power beforehand, the voltage and current which are usable need to be taken into account.
  * Also, the temperature of the cells need to be known so an over heating can ideally be prevented.
  *
  ******************************************************************************
  */
/* USER CODE END Header */


#ifndef BMS_H_
#define BMS_H_

class BMS {
	public:
		BMS();
		virtual ~BMS();

		bool setVoltage(float volt);
		bool setCurrent(float amp);
		bool setSoC(float soc);
		bool setTemp(unsigned short int tempArray[104]);

		float getVoltage();
		float getCurrent();
		float getSoC();
		float getTemp();
		float getPeakTemp();

	private:
		float current;
		float voltage;
		float stateOfCharge;
		unsigned short int peakTemp;
		unsigned short int overallTemp[104];

		bool savePeakTemp();
		// ...
};

#endif /* BMS_H_ */
