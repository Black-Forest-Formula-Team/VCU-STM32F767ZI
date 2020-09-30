/**
* @class CANController
*
* @brief
* @author Alex
* @date 03.04.2020
*
*
*/

#include "CANController.hpp"



CANController::CANController(CANHandle &canHandle) : _canHandle(canHandle)
{
	// do nothing here
}


void CANController::publish(CANFrame frame)
{
	// update each subscriber that listens to the same frame id as the id of the given frame
	for (auto it = _canFrameIds.begin(); it != _canFrameIds.end(); ++it)
	{
		if (frame.id == *it)
		{
			const int index = it - _canFrameIds.begin();
			ICANSubscriber *subscriber =_canSubscribers[index];
			subscriber->receive(frame);
		}
	}
}


void CANController::addSubscriber(ICANSubscriber &subscriber, CANFrameId id)
{
	_canSubscribers.push_back(&subscriber);
	_canFrameIds.push_back(id);
}


// shall be called from interrupt service procedure to distribute the received CAN frame to the subscribers
void CANController::receiveFromISR(void)
{

	CAN_RxHeaderTypeDef canRxHeader;

	/*init with default value*/
	canRxHeader.ExtId = 0;
	canRxHeader.StdId = 0;

	CANPayload RxPayload;


	if(HAL_CAN_GetRxFifoFillLevel(&_canHandle, CAN_RX_FIFO0))
	{/*frame in FIFO 0*/
		if(HAL_CAN_GetRxMessage(&_canHandle, CAN_RX_FIFO0, &canRxHeader, RxPayload.data.uint8))
			/*receive failed*/
			throw "receive frame is not possible";
	}
	else if (HAL_CAN_GetRxFifoFillLevel(&_canHandle, CAN_RX_FIFO1))
	{/*frame in FIFI 1*/
		if(HAL_CAN_GetRxMessage(&_canHandle, CAN_RX_FIFO1, &canRxHeader, RxPayload.data.uint8))
			/*receive failed*/
			throw "receive frame is not possible";
	}
	/*error because no frame is in the FIFOs*/
	else
		throw "no pending receive frame";

	/*CAN_RTR_REMOTE == 0x002U else ==0x0000U*/
	RxPayload.isRemoteFrame = canRxHeader.RTR>>1;


	/*set bitlength*/
	RxPayload.bitLength = canRxHeader.DLC*8;


	/*TODO: check the function of this value*/
//	canRxHeader.FilterMatchIndex;
//	canRxHeader.Timestamp;


	/*ceate the RxFrame*/
	CANFrame RxFrame = CANFrame(CANFrameId(canRxHeader.StdId,canRxHeader.ExtId,canRxHeader.IDE>>2), RxPayload);


	publish(RxFrame);
}


void CANController::send(CANFrame frame)
{
	/*Local values*/
	uint32_t u32canTxMailbox = 0;			// Param for the Tx mailbox
	CAN_TxHeaderTypeDef canTxHeader;		// Tx Header set all information for the transmission

/*mailbox handling*/

	/*check if ther are any empty mailboxes*/
	if (HAL_CAN_GetTxMailboxesFreeLevel(&_canHandle))
	{/*find the empty mailbox*/
		/*check mailbox 0*/
		if (!HAL_CAN_IsTxMessagePending(&_canHandle, CAN_TX_MAILBOX0))
		{/*mailbox0 is empty, use this for TX_message*/
			u32canTxMailbox = CAN_TX_MAILBOX0;
		}
		else if (!HAL_CAN_IsTxMessagePending(&_canHandle, CAN_TX_MAILBOX1))
		{/*mailbox1 is empty, use this for TX_message*/
			u32canTxMailbox = CAN_TX_MAILBOX1;
		}
		else
		{/*mailbox2 is empty, use this for TX_message*/
			u32canTxMailbox = CAN_TX_MAILBOX2;
		}
	}
	/*no empty mailbox, throw error-handling*/
	else throw "no empty mailbox";


	/*set the Tx Header with the CAN information*/
	/*set standard and extended Id for transmission*/
	canTxHeader.StdId = frame.id.standardId;
	canTxHeader.ExtId = frame.id.extendedId;
	/*specify if standard or extended Id is use*/
	if(frame.id.isExtendedFrame)
		/*use extended Id*/
		canTxHeader.IDE = CAN_ID_EXT;
	else
		/*use standard Id*/
		canTxHeader.IDE = CAN_ID_STD;

	/*specify the type of frame to transmission*/
	if ( frame.payload.isRemoteFrame)
		/*send remote frame*/
		canTxHeader.RTR = CAN_RTR_REMOTE;
	else
		/*send a Data frame*/
		canTxHeader.RTR = CAN_RTR_DATA;

	/*set length of dataframe*/
	canTxHeader.DLC = frame.payload.bitLength/8;
	/*diesable TransmitglobalTime*/
	canTxHeader.TransmitGlobalTime = DISABLE;


	/*start transmission*/
	if(HAL_CAN_AddTxMessage(&_canHandle, &canTxHeader, frame.payload.data.uint8, &u32canTxMailbox))
		/*transmission failed*/
		throw "send TX is not possible";

}
/** function to start the CAN communication*/
void CANController::start(void)
{

	if(HAL_CAN_Start(&_canHandle)) throw "Can can't start";

}
/**function to activate the Interrupt for CAN*/
void CANController::activateInterrupt (void)
{
	if(HAL_CAN_ActivateNotification(&_canHandle, CAN_IT_RX_FIFO0_MSG_PENDING)) throw "Interrupt can't activate";
	if(HAL_CAN_ActivateNotification(&_canHandle, CAN_IT_RX_FIFO1_MSG_PENDING)) throw "Interrupt can't activate";
	//HAL_CAN_ActivateNotification(&_canHandle, CAN_IT_RX_FIFO0_FULL);
	//HAL_CAN_ActivateNotification(&_canHandle, CAN_IT_RX_FIFO1_FULL);
}
/**function to deactivate the Interrupt for CAN*/
void CANController::deactivateInterrupt (void)
{
	if(HAL_CAN_DeactivateNotification(&_canHandle, CAN_IT_RX_FIFO0_MSG_PENDING)) throw "Interrupt can't deactivate";
	if(HAL_CAN_DeactivateNotification(&_canHandle, CAN_IT_RX_FIFO1_MSG_PENDING)) throw "Interrupt can't deactivate";
}

