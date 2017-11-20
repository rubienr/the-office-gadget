//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <inttypes.h>

class I2cBus
{
protected:

private:

public:
    uint8_t sclPin;
    uint8_t sdaPin;

    I2cBus(uint8_t sclPin, uint8_t sdaPin);
};
