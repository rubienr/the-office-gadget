//
// Created by rubienr on 08/11/17.
//

#include "Wifi.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>

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

Wifi::Wifi(Print& out) :
    out(out)
{
}

const char* Wifi::encryptionTypeToName(uint8_t encryptionTypeId)
{
    if (encryptionTypeId < sizeof(Wifi::EncryptionTypeToNameTranslation))
    {
        return Wifi::EncryptionTypeToNameTranslation[encryptionTypeId];
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
        bool isHidden;

        if (false == WiFi.getNetworkInfo(static_cast<uint8_t>(i), ssid, encryptionType, rssi, bssid, channel, isHidden))
        {
            continue;
        }

        uint8_t nbssid[] = {0, 0, 0, 0, 0, 0};
        if (bssid == nullptr)
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

void Wifi::enable()
{
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void Wifi::init()
{
    enable();
    out.println("WiFi diagnostic");
    WiFi.printDiag(out);
}

void Wifi::scan()
{
    int8_t numNetworksScanned = WiFi.scanNetworks();
    while (WiFi.scanComplete() < 0);
    printNetworksCallback(numNetworksScanned);
    WiFi.scanDelete();
    out.println("\n");
}

bool Wifi::connectAccesspoint(const char* ssid, const char* secret, uint8_t retry)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        wl_status_t status = WiFi.begin(ssid, secret);
        printConnectstatus(status, out);

        while ((WiFi.status() != WL_CONNECTED) && (retry-- > 0))
        {
            delay(250);
            out.print(".");
        }

        if ((WiFi.status() == WL_CONNECTED))
        {
            out.printf("wifi connected, ip %s\n", WiFi.localIP().toString().c_str());
            return true;
        }
        else
        {
            out.println("failed to connect wifi");
        }
        return false;
    }
    return true;
}

void Wifi::printConnectstatus(wl_status_t status, Print& out)
{
    const char* messagePrefix = "conn. stat. ";
    switch (status)
    {
        case WL_NO_SHIELD:
            break;

        case WL_IDLE_STATUS:
            out.printf("%s%s\n", messagePrefix, "WL_IDLE_STATUS");
            break;
        case WL_NO_SSID_AVAIL:
            out.printf("%s%s\n", messagePrefix, "WL_NO_SSID_AVAIL");
            break;
        case WL_SCAN_COMPLETED:
            out.printf("%s%s\n", messagePrefix, "WL_SCAN_COMPLETED");
            break;
        case WL_CONNECTED:
            out.printf("%s%s\n", messagePrefix, "WL_CONNECTED");
            break;
        case WL_CONNECT_FAILED:
            out.printf("%s%s\n", messagePrefix, "WL_CONNECT_FAILED");
            break;
        case WL_CONNECTION_LOST:
            out.printf("%s%s\n", messagePrefix, "WL_CONNECTION_LOST");
            break;
        case WL_DISCONNECTED:
            out.printf("%s%s\n", messagePrefix, "WL_DISCONNECTED");
            break;
    }
}
