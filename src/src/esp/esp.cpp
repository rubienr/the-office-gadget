//
// Created by rubienr on 08/11/17.
//

#include "esp.h"
#include <Arduino.h>

#include <SoftwareSerial.h>

ADC_MODE(ADC_VCC);

void initEsp(bool earaseConfigutation)
{
    if (earaseConfigutation)
    {
        ESP.eraseConfig();
    }
}

void printEspInfo(void)
{
    Serial.printf("shutdown reason: %s\nid %08X\nflash id %08X\nflash speed %u[Hz]\n Vcc %PRIi32",
                               ESP.getResetReason().c_str(),
                               ESP.getChipId(),
                               ESP.getFlashChipId(),
                               ESP.getFlashChipSpeed(),
                               ESP.getVcc()
    );
}
