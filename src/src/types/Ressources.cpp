//
// Created by rubienr on 08/11/17.
//

#include "Ressources.h"
#include "../serial/serial.h"

EarlyInit::EarlyInit()
{
    initSerial();
}

Ressources::Ressources() :
    earlyInit(),
    i2cBus(D1, D2),
    keyboard(i2cBus),
    displays(i2cBus),
    ledStrip(),
    builtin(),
    sensors(i2cBus)
{
}

void Ressources::init()
{
    builtin.init();
    keyboard.init();
    displays.init();
    sensors.init();
    ledStrip.init();
}
