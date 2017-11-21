//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <inttypes.h>

class Print;

class Wifi
{
private:
    static const char* EncryptionTypeToNameTranslation[];
    const char* encryptionTypeToName(uint8_t encyptionTypeId);
    void printNetworksCallback(int8_t numNetworksFound);

protected:
    Print &out;

public:
    void scan(void);
    void enable(void);
    void init(void);

    Wifi(Print &serial);
};
