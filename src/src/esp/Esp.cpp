//
// Created by rubienr on 08/11/17.
//

#include "Esp.h"
#include <Esp.h>
#include <Arduino.h>
#include <Print.h>

ADC_MODE(ADC_VCC);

Esp::Esp(Print &out) :
    out(out)
{
}

void Esp::init(bool earaseConfigutation)
{
    if (earaseConfigutation)
    {
        ESP.eraseConfig();
    }
}

void Esp::printInfo(void)
{
    out.printf("shutdown reason: %s\nid %08X\nflash id %08X\nflash speed %u[Hz]\n Vcc %PRIi32",
                  ESP.getResetReason().c_str(),
                  ESP.getChipId(),
                  ESP.getFlashChipId(),
                  ESP.getFlashChipSpeed(),
                  ESP.getVcc()
    );
}
