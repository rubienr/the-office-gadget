//
// Created by rubienr on 08/11/17.
//

#include "Wifi.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Print.h>

const char* Wifi::EncryptionTypeToNameTranslation[]
              {
                  "0",
                  "1",
                  "WPA / PSK",
                  "3",
                  "WPA2 / PSK",
                  "WEP",
                  "6",
                  "open network",
                  "WPA / WPA2 / PSK",
                  "9"
              };

Wifi::Wifi(Print &out) :
    out(out)
{
}

const char* Wifi::encryptionTypeToName(uint8_t encyptionTypeId)
{
    if (encyptionTypeId < sizeof(Wifi::EncryptionTypeToNameTranslation))
    {
        return Wifi::EncryptionTypeToNameTranslation[encyptionTypeId];
    }
    return "-";
}

void Wifi::printNetworksCallback(int8_t numNetworksFound)
{
    out.printf("%"PRIi8" networks found\n", numNetworksFound);
    out.println("SSID CHANNEL RSSI[dBm] ENC_TYPE MAC HIDDEN");
    --numNetworksFound;

    for (int8_t i = numNetworksFound; i >= 0; --i)
    {
        uint8_t* bssid;
        String  ssid;
        uint8_t encryptionType;
        int32_t rssi, channel;
        bool    isHidden;

        if (false == WiFi.getNetworkInfo(i, ssid, encryptionType, rssi, bssid, channel, isHidden))
        {
            continue;
        }

        uint8_t nbssid[] = {0, 0, 0, 0, 0, 0};
        if (bssid == NULL)
        {
            bssid = nbssid;
        }

        out.printf(
            "# %"PRIi8" ss %s ch %"PRIi16" rs  %"PRIi16" enc %s >%"PRIu16"< mac %02x:%02x:%02x:%02x:%02x:%02x hidden  %"PRIu8"\n",
            i + 1,
            ssid.c_str(),
            (int16_t)channel,
            (int16_t)rssi,
            encryptionTypeToName(encryptionType),
            (uint16_t)encryptionType,
            bssid[0],
            bssid[1],
            bssid[2],
            bssid[3],
            bssid[4],
            bssid[5],
            isHidden
        );
    }
}

void Wifi::enable(void)
{
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void Wifi::init(void)
{
    enable();
    out.println("WiFi diagnostic");
    WiFi.printDiag(out);
}

void Wifi::scan(void)
{
    int8_t numNetworksScanned = WiFi.scanNetworks();
    while (WiFi.scanComplete() < 0);
    printNetworksCallback(numNetworksScanned);
    WiFi.scanDelete();
    out.println("\n");
}
