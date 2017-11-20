//
// Created by rubienr on 08/11/17.
//

#include "Sensors.h"

Sensors::Sensors(const I2cBus& i2cBus) :
    i2cBus(i2cBus),
    oneWire(D4),
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

float Sensors::getTemperature(uint8_t idx)
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
