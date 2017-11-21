//
// Created by rubienr on 08/11/17.
//

#include "Sensors.h"

#include "../ressources/I2cBusConfig.h"
#include "../ressources/OneWireBusConfig.h"

Sensors::Sensors(const I2cBusConfig& i2cBusConfig, const OneWireBusConfig& oneWireBusConfig) :
    i2cBusConfig(i2cBusConfig),
    oneWireBusConfig(oneWireBusConfig),
    oneWire(oneWireBusConfig.sdaPin),
    temperatureSensors(&oneWire),
    temperatureSensor0Address(0xff),
    lightSensorAddress(0x23),
    lightSensor(lightSensorAddress)
{
    temperatureSensors.getAddress(&temperatureSensor0Address, 0);
}

void Sensors::measureTemperature()
{
    temperatureSensors.requestTemperaturesByAddress(&temperatureSensor0Address);
}

float Sensors::getTemperature()
{
    return temperatureSensors.getTempC(&temperatureSensor0Address);
}

uint16_t Sensors::currentLux()
{
    return lightSensor.readLightLevel();
}

void Sensors::init()
{
    temperatureSensors.begin();
    lightSensor.begin(BH1750_CONTINUOUS_HIGH_RES_MODE);
}
