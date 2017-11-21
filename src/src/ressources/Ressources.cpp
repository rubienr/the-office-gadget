//
// Created by rubienr on 08/11/17.
//

#include "Ressources.h"

EarlyInit::EarlyInit()
{
    Serial.begin(115200);
    while (!Serial);
}

Print& EarlyInit::debugOut()
{
    return Serial;
}

Ressources::Ressources() :
    earlyInitializer(),
    i2cCfg(D1, D2),
    oneWireCfg(D5),
    displays(i2cCfg),
    esp(earlyInitializer.debugOut()),
    builtin(),
    keyboard(i2cCfg),
    sensors(i2cCfg, oneWireCfg),
    ledStrip(),
    wifi(earlyInitializer.debugOut()),
    webService(earlyInitializer.debugOut())
{
}

void Ressources::init()
{
    displays.init();
    esp.init();
    esp.printInfo();
    builtin.init();
    keyboard.init();
    sensors.init();
    ledStrip.init();
    wifi.init();
    webService.init();
}
