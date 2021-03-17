# VCU-STM32F767ZI
For the Formula Student VCU - Inverter, Sensor &amp; BMS communications
<p align="center">
  <a href="https://blackforestformula.hs-offenburg.de/">
    <img alt="BFFT_Logo" title="BFFT" src="https://scontent-frt3-1.xx.fbcdn.net/v/t1.0-9/69419451_117866062911797_4569414645357477888_o.jpg?_nc_cat=107&ccb=1-3&_nc_sid=973b4a&_nc_ohc=b5rqMomf8_AAX8x_CMD&_nc_ht=scontent-frt3-1.xx&oh=7ab30784f93fdf5ad846196156f856e6&oe=606D20C4" width="1000">
  </a>
</p>

# Black Forest Formula Team - Formula Student VCU 2021

This repository lays the foundation for the VCU development of the Black Forest Formula Team located in Offenburg. You can find an overview to get started in this ReadMe, for more information we suggest to refer to the [Wiki](https://github.com/Black-Forest-Formula-Team/VCU-STM32F767ZI/wiki) you can find in this Repo.
____________________


## Repository organisation

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


  - [Introduction](#introduction)
  - [Getting started](#getting-started)
    - [CAN Bus Communication](#can-bus-communication)
- [Inverter Control](#inverter-control)
  - [To-Do](#to-do)
    - [Monitoring and Safety](#monitoring-and-safety)
    - [HiL-Testing](#hil-testing)
    - [Connect the Driver Interface](#connect-the-driver-interface)
    - [Sensor-Data](#sensor-data)
    - [Inverter Control](#inverter-control-1)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Introduction
This project represents the VCU development of the Formula Student Team from Hochschule Offenburg (Germany). The focus lays on the documentation for new team members which allows them a smooth start to improve our software.
Our VCU is a STM32-F767ZI board which uses the HAL-Lib for CAN-Communication.


____________________
## Getting started
First of all check out the project structure in the [Wiki](https://github.com/Black-Forest-Formula-Team/VCU-STM32F767ZI/wiki/Project-Structure).
HAL gets initialized in the main.c, the rest of the CAN-communication happens in mymain.ccp.



### CAN Bus Communication
To enable the CAN-communication start CAN and activate notification to receive messeges.


```
	
	if (HAL_CAN_Start(&hcan1) != HAL_OK)
	{
		Error_Handler();
	}

	if (HAL_CAN_ActivateNotification(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_RX_FIFO1_MSG_PENDING | CAN_IT_TX_MAILBOX_EMPTY) != HAL_OK)
	{
		Error_Handler();
	}
	
```

#### Send a message
In mymain.ccp you can find a simple example for sending one CAN-Message.

```

	// prepare header
	CAN_TxHeaderTypeDef header;
	// set standard id
	header.StdId = 42;
	// use standard id
	header.IDE = CAN_ID_STD;
	// this is a data frame, not a remote frame, because we have data to send
	header.RTR = CAN_RTR_DATA;
	// data length, we send eight bytes
	header.DLC = 8;
	uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint32_t txMailbox_used_to_store;

		if (HAL_CAN_AddTxMessage(&hcan1, &header, data, &txMailbox_used_to_store) != HAL_OK)
		{
			puts("error");
			// Error_Handler();
		}
```

#### Receive a message
Interrupt routine is implemented but has to be validated and adjusted.


# Inverter Control
Dokumentation for inverterhandling (left and right inverter). [Here](https://github.com/Black-Forest-Formula-Team/VCU-STM32F767ZI/wiki/Inverter-Control) you can find it in detail.

## To-Do

### Receiving CAN-Messages
Setting up CAN-Filter and Interrupts for receiving CAN-Messeges from sensors for example.

### Monitoring and Safety
Implementation of saftey and monitoring function which triggers e.g. derating.

### HiL-Testing
Validate and check if the VCU works properly. Create test cases with our HiL-Box if all the functions are correctly implemented and applied.

### Connect the Driver Interface
The driver interface shows important data e.g. velocity. Implement classes/functions in the VCU to send sensor data to a display via CAN.

### Sensor-Data
Implementation of classes and functions to handle the sensor data (receiving).

### Inverter Control
Handle the control of the inverters and e-machine via CAN.
