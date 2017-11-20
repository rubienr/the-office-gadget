//
// Created by rubienr on 08/11/17.
//

#include "BuiltIn.h"

#include <Arduino.h>

void BuiltIn::ledOn()
{
    digitalWrite(BUILTIN_LED, true);
}

void BuiltIn::ledOff()
{
    digitalWrite(BUILTIN_LED, false);
}

void BuiltIn::ledToggle()
{
    digitalWrite(BUILTIN_LED, (0x01 & ~digitalRead(BUILTIN_LED)));
}

void BuiltIn::init()
{
    pinMode(BUILTIN_LED, OUTPUT);
}
