//
// Created by rubienr on 08/11/17.
//

#include "Resources.h"

#include <FS.h>

EarlyInit::EarlyInit()
{
    Serial.begin(115200);
    while (!Serial);

    if (!SPIFFS.begin())
    {
        Serial.println("failed to initialize filesystem");
    }
}

Print& EarlyInit::debugOut()
{
    return Serial;
}

Resources::Resources() :
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

void Resources::init()
{
    displays.init();
    esp.init();
    esp.printInfo();
    builtin.init();
    keyboard.init();
    sensors.init();
    ledStrip.init();
    wifi.init();
    displays.display0.print("connecting wifi...");
    displays.display0.displayBuffer();
    wifi.connectAccesspoint("ssid", "secret");
    displays.display0.println(" done");
    displays.display0.displayBuffer();
    webService.init();
}
