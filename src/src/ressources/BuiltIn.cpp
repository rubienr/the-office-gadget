//
// Created by rubienr on 08/11/17.
//

#include "BuiltIn.h"
#include <inttypes.h>
#include <Arduino.h>

void BuiltIn::ledOn()
{
    digitalWrite(BUILTIN_LED, 0);
}

void BuiltIn::ledOff()
{
    digitalWrite(BUILTIN_LED, 1);
}

void BuiltIn::ledToggle()
{
    digitalWrite(BUILTIN_LED, static_cast<uint8_t>(0x01 & ~digitalRead(BUILTIN_LED)));
}

void BuiltIn::init()
{
    pinMode(BUILTIN_LED, OUTPUT);
    ledOff();
}
