//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <inttypes.h>
#include <FastLED.h>
#include <Arduino.h>

extern CFastLED FastLED;

template<uint8_t DATA_PIN, uint8_t NUM_LEDS>
class LedStrip
{
protected:

private:

public:
    uint8_t       brightness;
    CRGB          leds[NUM_LEDS];

    CFastLED& fastLED;

    LedStrip(uint8_t brightness = 8) :
        brightness(brightness),
        fastLED(FastLED)
    {
    }

    void init()
    {
        fastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
        fastLED.setBrightness(brightness);
        pinMode(DATA_PIN, OUTPUT);
    }
};

