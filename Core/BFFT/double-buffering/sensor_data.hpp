/*
 * values.hpp
 *
 *  Created on: 11.08.2020
 *      Author: Alex
 */

#ifndef SRC_SENSOR_DATA_HPP_
#define SRC_SENSOR_DATA_HPP_

#include "frutil/FreeRTOSUtils.hpp"
#include "sensor_data.hpp"

using namespace frutil;
using namespace frutil::mutex;


template <class T>
class allow_volatile_assignent : public T
{
	using This = allow_volatile_assignent<T>;

public:
	using T::T;

    This volatile& operator= (This const &rhs) volatile
    {
        *this = rhs;
        return *this;
    }

    This& operator= (This volatile &rhs)
    {
    	*this = rhs;
    	return *this;
    }
};



/************************************************************************************************************/
template <class T>
class PhysicalQuantity
{
	//static_assert(std::is_base_of<PhysicalUnit, U>::value, "U must inherit from PhysicalUnit");

public:
	T value;

	PhysicalQuantity(T value)
	{
		this->value = value;
	}
};

/*
#define CREATE_PHYSICAL_QUANTITY2(NAME, TYPE) \
	class NAME : public PhysicalQuantity<TYPE>\
	{\
	public:\
		using PhysicalQuantity::PhysicalQuantity;\
	};
*/


/************************************************************************************************************/
class Entity {};

// #define CREATE_ENTITY(NAME) class NAME: public Entity {};


/************************************************************************************************************/
template <class E, class Q>
class EntityQuantity
{
public:
	Q quantity = (Q) 0; // dummy value, this gets initialized by constructor

	EntityQuantity(Q quantity)
	{
		this->quantity = quantity;
	}
};

/*
#define CREATE_ENTITY_QUANTITY(NAME, ENTITY, QUANTITY, DEFAULT_QUANTITY) \
	class NAME : public EntityQuantity<ENTITY, QUANTITY>\
	{\
	public: \
		static QUANTITY generateDefaultQuantity()\
		{\
			return DEFAULT_QUANTITY;\
		}\
		\
		NAME() : EntityQuantity<ENTITY, QUANTITY>(generateDefaultQuantity())\
		{}\
		\
		using EntityQuantity::EntityQuantity;\
	};
*/


/************************************************************************************************************/
// Definitions of Units, Quantities, Entities and Entity Quantities

/*
CREATE_PHYSICAL_QUANTITY(Speed_MeterPerSecond_Float, float)
CREATE_PHYSICAL_QUANTITY(Current_Ampere_Float, float)
CREATE_PHYSICAL_QUANTITY(Voltage_Volt_Float, float)
CREATE_PHYSICAL_QUANTITY(Power_Watt, float)
*/
using Speed_MeterPerSecond_Float	= PhysicalQuantity<float>;
using Current_Ampere_Float		 	= PhysicalQuantity<float>;
using Voltage_Volt_Float 			= PhysicalQuantity<float>;
using Power_Watt_Float 				= PhysicalQuantity<float>;

/*
CREATE_ENTITY(WheelFrontLeft)
CREATE_ENTITY(WheelFrontRight)
CREATE_ENTITY(WheelBackLeft)
CREATE_ENTITY(WheelBackRight)

CREATE_ENTITY(InverterLeft)
CREATE_ENTITY(InverterRight)
*/
class WheelFrontLeft 	: public Entity {};
class WheelFrontRight 	: public Entity {};
class WheelBackLeft 	: public Entity {};
class WheelBackRight 	: public Entity {};

class InverterLeft 		: public Entity {};
class InverterRight		: public Entity {};

/*
CREATE_ENTITY_QUANTITY(WheelFrontLeft_Speed, WheelFrontLeft, Speed_MeterPerSecond_Float, Speed_MeterPerSecond_Float(0))
CREATE_ENTITY_QUANTITY(WheelFrontRight_Speed, WheelFrontRight, Speed_MeterPerSecond_Float, Speed_MeterPerSecond_Float(0))
CREATE_ENTITY_QUANTITY(WheelBackLeft_Speed, WheelBackLeft, Speed_MeterPerSecond_Float, Speed_MeterPerSecond_Float(0))
CREATE_ENTITY_QUANTITY(WheelBackRight_Speed, WheelBackRight, Speed_MeterPerSecond_Float, Speed_MeterPerSecond_Float(0))

CREATE_ENTITY_QUANTITY(InverterLeft_Current, InverterLeft, Current_Ampere_Float, Current_Ampere_Float(0))
CREATE_ENTITY_QUANTITY(InverterLeft_Voltage, InverterLeft, Voltage_Volt_Float, Voltage_Volt_Float(0))
CREATE_ENTITY_QUANTITY(InverterLeft_Power, InverterLeft, Power_Watt, Power_Watt(0))

CREATE_ENTITY_QUANTITY(InverterRight_Current, InverterRight, Current_Ampere_Float, Current_Ampere_Float(0))
CREATE_ENTITY_QUANTITY(InverterRight_Voltage, InverterRight, Voltage_Volt_Float, Voltage_Volt_Float(0))
CREATE_ENTITY_QUANTITY(InverterRight_Power, InverterRight, Power_Watt, Power_Watt(0))
*/

using WheelFrontLeft_Speed 	= EntityQuantity<WheelFrontLeft, Speed_MeterPerSecond_Float>;
using WheelFrontRight_Speed = EntityQuantity<WheelFrontLeft, Speed_MeterPerSecond_Float>;
using WheelBackLeft_Speed 	= EntityQuantity<WheelFrontLeft, Speed_MeterPerSecond_Float>;
using WheelBackRight_Speed 	= EntityQuantity<WheelFrontLeft, Speed_MeterPerSecond_Float>;

using InverterLeft_Current 	= allow_volatile_assignent<EntityQuantity<InverterLeft, Current_Ampere_Float>>;
using InverterLeft_Voltage 	= EntityQuantity<InverterLeft, Voltage_Volt_Float>;
using InverterLeft_Power 	= EntityQuantity<InverterLeft, Power_Watt_Float>;

using InverterRight_Current = EntityQuantity<InverterRight, Current_Ampere_Float>;
using InverterRight_Voltage = EntityQuantity<InverterRight, Voltage_Volt_Float>;
using InverterRight_Power 	= EntityQuantity<InverterRight, Power_Watt_Float>;


/************************************************************************************************************/
class SensorData
{
public:
	WheelFrontLeft_Speed 	wheelFrontLeft_speed 	= Speed_MeterPerSecond_Float(0);
	WheelFrontRight_Speed 	wheelFrontRight_speed 	= Speed_MeterPerSecond_Float(0);
	WheelBackLeft_Speed 	wheelBackLeft_speed 	= Speed_MeterPerSecond_Float(0);
	WheelBackRight_Speed 	wheelBackRight_speed 	= Speed_MeterPerSecond_Float(0);

	InverterLeft_Current 	inverterLeft_current	= Current_Ampere_Float(0);
	InverterLeft_Voltage 	inverterLeft_voltage	= Voltage_Volt_Float(0);
	InverterLeft_Power 		inverterLeft_power 		= Power_Watt_Float(0);

	InverterRight_Current 	inverterRight_current 	= Current_Ampere_Float(0);
	InverterRight_Voltage 	inverterRight_voltage	= Voltage_Volt_Float(0);
	InverterRight_Power 	inverterRight_power 	= Power_Watt_Float(0);

	SensorData() = default;

	SensorData(SensorData const volatile &) { }

	SensorData& operator= (SensorData const volatile &rhs)
	{
		*this = rhs;
		return *this;
	}
};


class SensorDataAccessGuard
{
	MutexCertainGuard _guard;

public:
	SensorData volatile &sensorData;

	SensorDataAccessGuard(MutexCertainGuard guard, SensorData volatile &sensorData) : _guard(guard), sensorData(sensorData)
	{}
};


class SensorDataBuffer
{
	MutexAllocatedLocally _mutex;
	volatile SensorData _sensorData;

public:
	SensorData getSnapshot()
	{
		SuspendSchedulerAndInterruptsGuard();
		SensorData sensorData = _sensorData;
		return sensorData;
	}

	SensorDataAccessGuard getAccessGuard()
	{
		return SensorDataAccessGuard(MutexCertainGuard(_mutex, Ticks::Max_Delay), _sensorData);
	}
};


#endif /* SRC_DOUBLE_BUFFERING_SENSOR_DATA_HPP_ */
