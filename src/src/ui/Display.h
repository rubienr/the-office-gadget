//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <SSD1306.h>

#include "../ressources/I2cBusConfig.h"

class Display : public SSD1306
{
private:

protected:

public:
    Display(uint8_t _address, uint8_t _sda, uint8_t _scl);
    void displayBuffer();
};

class DisplayCombo
{
private:

protected:

public:
    Display display0;
    Display display1;

    explicit DisplayCombo(const I2cBusConfig& i2cBus);
    void init();
};
