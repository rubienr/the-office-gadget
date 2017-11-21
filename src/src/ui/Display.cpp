//
// Created by rubienr on 08/11/17.
//

#include "Display.h"

DisplayCombo::DisplayCombo(const I2cBusConfig& i2cBus) :
    display0(0x3c, i2cBus.sdaPin, i2cBus.sclPin),
    display1(0x3d, i2cBus.sdaPin, i2cBus.sclPin)
{
}

Display::Display(uint8_t _address, uint8_t _sda, uint8_t _scl) :
    SSD1306(_address, _sda, _scl)
{
}

void Display::displayBuffer()
{
    drawLogBuffer(0, 0);
    display();
}

void DisplayCombo::init()
{
    uint8_t rows = 5, maxCols = 30, contrast = 128;
    display0.setFont(ArialMT_Plain_10);
    display0.init();
    display0.flipScreenVertically();
    display0.setContrast(contrast);
    display0.setLogBuffer(rows, maxCols);

    display1.setFont(ArialMT_Plain_10);
    display1.init();
    display1.flipScreenVertically();
    display1.setContrast(contrast);
    display1.setLogBuffer(rows, maxCols);
}

