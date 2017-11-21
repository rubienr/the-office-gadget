//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <inttypes.h>

extern "C" {
#include "include/wl_definitions.h"
}

class Print;

class Wifi
{
private:
    static const char* EncryptionTypeToNameTranslation[];
    const char* encryptionTypeToName(uint8_t encyptionTypeId);
    void printNetworksCallback(int8_t numNetworksFound);

protected:
    Print& out;

public:
    explicit Wifi(Print& serial);
    void scan();
    void enable();
    void init();
    void connectAccesspoint(const char* ssid, const char* secret);
    void printConnectstatus(wl_status_t status, Print& out);
};
