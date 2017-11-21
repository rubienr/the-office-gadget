//
// Created by rubienr on 21/11/17.
//

#pragma once

#include <inttypes.h>
#include <ESP8266WebServer.h>

class Print;

class WebService : public ESP8266WebServer
{
private:

protected:
    Print& out;

public:
    WebService(Print& out, int16_t port = 80);
    void init();
};

