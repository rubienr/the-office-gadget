//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <inttypes.h>

class Wifi
{
protected:

private:
    static const char* EncryptionTypeToNameTranslation[];
    const char* encryptionTypeToName(uint8_t encyptionTypeId);
    void printNetworksCallback(int8_t numNetworksFound);

public:
    void scanWifi(void);
    void enableWifi(void);
    void initWifi(void);

    Wifi();
};
