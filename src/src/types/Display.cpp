//
// Created by rubienr on 08/11/17.
//

#include "Display.h"

#include <SSD1306.h>

DisplayCombo::DisplayCombo(const I2cBus& i2cBus) :
    display0(0x3c, i2cBus.sdaPin, i2cBus.sclPin),
    display1(0x3d, i2cBus.sdaPin, i2cBus.sclPin)
{
}

void DisplayCombo::init()
{
    display0.setFont(ArialMT_Plain_10);
    display0.init();
    display0.flipScreenVertically();
    display0.setContrast(255);
    display0.setLogBuffer(5, 30);
    display0.clear();

    display1.setFont(ArialMT_Plain_10);
    display1.init();
    display1.flipScreenVertically();
    display1.setContrast(255);
    display1.setLogBuffer(5, 30);
    display1.clear();
}

