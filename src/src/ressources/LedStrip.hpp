//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <inttypes.h>
#include <FastLED.h>
#include <Arduino.h>

template<uint8_t DATA_PIN, uint8_t NUM_LEDS>
class LedStrip
{
protected:

private:

public:
    uint8_t brightness;
    CRGB    leds[NUM_LEDS];

    CFastLED& fastLED;

    explicit LedStrip(uint8_t brightness = 8) :
        brightness(brightness),
        fastLED(FastLED)
    {
    }

    void init()
    {
        fastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
        fastLED.setBrightness(brightness);
        pinMode(DATA_PIN, OUTPUT);
    }
};

