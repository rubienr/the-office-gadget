//
// Created by rubienr on 08/11/17.
//

#pragma once

#include "LedStrip.h"
#include "I2cBus.h"
#include "Keyboard.h"
#include "Display.h"
#include "BuiltIn.h"
#include "Sensors.h"

class EarlyInit
{
public:
    EarlyInit();
};

class Ressources
{
protected:

private:

public:
    EarlyInit    earlyInit;
    LedStrip     ledStrip;
    const I2cBus i2cBus;
    Keyboard     keyboard;
    DisplayCombo displays;
    BuiltIn      builtin;
    Sensors      sensors;

    Ressources();

    void init();
};

