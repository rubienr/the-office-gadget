//
// Created by rubienr on 21/11/17.
//

#pragma once

#include <inttypes.h>

#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

class Print;
class MDNSResponder;

class WebService : public ESP8266WebServer
{
private:

protected:
    Print& out;
    ESP8266HTTPUpdateServer updateServer;
    MDNSResponder& mdns;

public:
    explicit WebService(Print& out, int16_t port = 80);
    void init();
};

