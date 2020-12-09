#include <frame/CanFrame.hpp>
#include <frame/Can2AFrameId.hpp>
#include <frame/Can2BFrameId.hpp>
#include <frame/CanPayloadValidated.hpp>
#include <frame/CanPayload.hpp>
#include <subscriber_registry/ICanSubscriberRegistry.hpp>
#include <subscriber_registry/CanSubscriberRegistry.hpp>
#include "Can2A2BControllerSTM32F767ZI.hpp"


static void test()
{
	CanPayload payload;
	payload.isRemoteFrame = false;
	payload.bitLength = 8;
	payload.data.uint8Array[3] = 0xAB;
	CanPayload payload_copied = payload;
	payload_copied = payload;

	CanPayloadValidated validated_payload(payload);
	CanPayloadValidated validated_payload_copied = validated_payload;
	validated_payload_copied = validated_payload;

	Can2AFrameId can_2a_frame_id(0x1337);
	Can2AFrameId can_2a_frame_id_copied = can_2a_frame_id;
	can_2a_frame_id_copied = can_2a_frame_id;

	Can2AFrame can_2a_frame(can_2a_frame_id, validated_payload);
	Can2AFrame can_2a_frame_copied = can_2a_frame;
	can_2a_frame_copied = can_2a_frame;

	Can2BFrameId can_2b_frame_id(0x1337, 0xBEEF);
	Can2BFrameId can_2b_frame_id_copied = can_2b_frame_id;
	can_2b_frame_id_copied = can_2b_frame_id;

	Can2BFrame can_2b_frame(can_2b_frame_id, validated_payload);
	Can2BFrame can_2b_frame_copied = can_2b_frame;
	can_2b_frame_copied = can_2b_frame;

	CAN_HandleTypeDef canHandle;
	Can2A2BControllerSTM32F767ZI canControllerSTM32F767ZI(canHandle);

	ICan2ASender& can_2a_sender = canControllerSTM32F767ZI;
	ICan2BSender& can_2b_sender = canControllerSTM32F767ZI;
	ICan2AReceiver& can_2a_receiver = canControllerSTM32F767ZI;
	ICan2BReceiver& can_2b_receiver = canControllerSTM32F767ZI;

	can_2a_sender.send(can_2a_frame);
	can_2b_sender.send(can_2b_frame);
	can_2a_receiver.receive(can_2a_frame);
	can_2b_receiver.receive(can_2b_frame);

	ICan2ASubscriber* aptr;
	Can2ASubscriberRegistry<32> can_2a_subscriber_registry;
	can_2a_subscriber_registry.addSubscriber(can_2a_frame_id, *aptr);
	can_2a_subscriber_registry.removeSubscriber(can_2a_frame_id, *aptr);
	can_2a_subscriber_registry.removeSubscriber(*aptr);
	// TODO: add sub

	Can2BSubscriberRegistry<32> can_2b_subscriber_registry;
	// TODO: add sub
}
