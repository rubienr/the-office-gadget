//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <OneWire.h>
#include <BH1750.h>
#include <DallasTemperature.h>

#include "I2cBus.h"

class Sensors
{
protected:

private:

public:
    OneWire           oneWire;
    DallasTemperature temperatureSensors;
    uint8_t           temperatureSensor0Address;

    const I2cBus& i2cBus;
    uint8_t lightSensorAddress;
    BH1750  lightSensor;

    Sensors(const I2cBus& i2cBus);

    void measureTemperature();

    float getTemperature(uint8_t idx = 0);

    uint16_t currentLux();

    void init();
};
