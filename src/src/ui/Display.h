//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <SSD1306.h>

#include "../ressources/I2cBusConfig.h"

class DisplayCombo
{
private:

protected:

public:
    SSD1306 display0;
    SSD1306 display1;

    DisplayCombo(const I2cBusConfig& i2cBus);
    void init();
};
