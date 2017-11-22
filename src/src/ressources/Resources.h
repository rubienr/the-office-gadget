//
// Created by rubienr on 08/11/17.
//

#pragma once

#include "../esp/Esp.h"
#include "LedStrip.hpp"
#include "I2cBusConfig.h"
#include "OneWireBusConfig.h"
#include "../ui/Keyboard.h"
#include "../ui/Display.h"
#include "BuiltIn.h"
#include "../sensors/Sensors.h"
#include "../wifi/Wifi.h"
#include "../web-service/WebService.h"

class Print;

class EarlyInit
{
private:

protected:

public:
    EarlyInit();
    Print& debugOut();
};

class Resources
{
protected:

private:

public:
    EarlyInit              earlyInitializer;
    Esp                    esp;
    LedStrip<D3, 64>       ledStrip;
    const I2cBusConfig     i2cCfg;
    const OneWireBusConfig oneWireCfg;
    Keyboard               keyboard;
    DisplayCombo           displays;
    BuiltIn                builtin;
    Sensors                sensors;
    Wifi                   wifi;
    WebService             webService;

    Resources();

    void init();
};

