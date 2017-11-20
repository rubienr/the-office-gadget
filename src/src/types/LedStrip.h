//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <inttypes.h>
#include <FastLED.h>
#include <Arduino.h>

class LedStrip
{
protected:

private:

public:
    static const uint8_t brightness    = 8;
    static const uint8_t numLeds       = 64;
    static const uint8_t dataPinNumber = D3;
    CRGB                 leds[numLeds];

    CFastLED& fastLED;

    LedStrip();

    void init();
};
