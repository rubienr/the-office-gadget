//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <SSD1306.h>

#include "I2cBus.h"

class DisplayCombo
{
protected:

private:

public:
    SSD1306 display0;
    SSD1306 display1;

    DisplayCombo(const I2cBus& i2cBus);

    void init();
};
