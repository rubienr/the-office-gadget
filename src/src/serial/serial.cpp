//
// Created by rubienr on 08/11/17.
//

#include "serial.h"

#include <Arduino.h>
#include <SoftwareSerial.h>

void initSerial(void)
{
    Serial.begin(115200);
    // Wait for serial port to connect. Needed for native USB port.
    while (!Serial);
}
