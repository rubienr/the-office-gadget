//
// Created by rubienr on 23/11/17.
//

#pragma once

#include "ConfigFromToJson.hpp"

namespace config {
namespace wifi {
namespace fields {

struct Ssid : public Uint8FromToJsonField
{
    Ssid() :
        Uint8FromToJsonField("ssid")
    {
    }
};

struct Password : public Uint8FromToJsonField
{
    Password() :
        Uint8FromToJsonField("password")
    {
    }
};

struct ConnectRetry : public Uint8FromToJsonField
{
    ConnectRetry() :
        Uint8FromToJsonField("connect_retry")
    {
    }
};

struct TimeoutMs : public Uint8FromToJsonField
{
    TimeoutMs() :
        Uint8FromToJsonField("timeout_ms")
    {
    }
};
}

typedef FromToJsonCompositum<
    fields::TimeoutMs,
    fields::Password,
    fields::ConnectRetry,
    fields::TimeoutMs> FromToJson;
}
}
