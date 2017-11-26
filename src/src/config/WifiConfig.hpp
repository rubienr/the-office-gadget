//
// Created by rubienr on 23/11/17.
//

#pragma once

#include "ConfigFromToJson.hpp"

class WifiConfiguration
{
public:

    struct Enabled : public BoolFromToJsonField
    {
        static const uint8_t MaxBooleanStringLength = 5;

        Enabled() :
            BoolFromToJsonField("isEnabled", MaxBooleanStringLength)
        {
        }
    };

    struct Ssid : public StringFromToJsonField
    {
        static const uint8_t MaxSsidStringLength = 32;

        Ssid() :
            StringFromToJsonField("ssid", MaxSsidStringLength)
        {
        }
    };

    struct Password : public StringFromToJsonField
    {
        static const uint8_t MaxPasswordLength = 64;

        Password() :
            StringFromToJsonField("pwd", MaxPasswordLength)
        {
        }
    };

    struct ConnectRetry : public Uint8FromToJsonField
    {
        static const uint8_t MaxUint8StringLength = 3;

        ConnectRetry() :
            Uint8FromToJsonField("connectRetry", MaxUint8StringLength)
        {
        }
    };

    struct TimeoutMs : public Uint16FromToJsonField
    {
        static const uint8_t MaxUint16StringLength = 5;

        TimeoutMs() :
            Uint16FromToJsonField("timeoutMs", MaxUint16StringLength)
        {
        }
    };

    typedef FromToJson<
        WifiConfiguration::Enabled,
        WifiConfiguration::Ssid,
        WifiConfiguration::Password,
        WifiConfiguration::TimeoutMs,
        WifiConfiguration::ConnectRetry
    > Data;
};
