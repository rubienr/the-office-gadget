//
// Created by rubienr on 08/11/17.
//

#include "Esp.h"
#include <Esp.h>

ADC_MODE(ADC_VCC);

Esp::Esp(Print& out) :
    out(out)
{
}

void Esp::init(bool eraseConfiguration)
{
    if (eraseConfiguration)
    {
        ESP.eraseConfig();
    }
}

void Esp::printInfo()
{
    out.printf("shutdown reason: %s\nid %08X\nflash id %08X\nflash speed %u[Hz]\n Vcc %PRIi32",
               ESP.getResetReason().c_str(),
               ESP.getChipId(),
               ESP.getFlashChipId(),
               ESP.getFlashChipSpeed(),
               ESP.getVcc()
    );
}
