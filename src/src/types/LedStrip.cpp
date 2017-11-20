//
// Created by rubienr on 08/11/17.
//

#include "LedStrip.h"

extern CFastLED FastLED;

LedStrip::LedStrip() :
    fastLED(FastLED)
{
}

void LedStrip::init()
{
    fastLED.addLeds<WS2811, dataPinNumber, GRB>(leds, numLeds);
    fastLED.setBrightness(brightness);
    pinMode(dataPinNumber, OUTPUT);
}
