//
// Created by rubienr on 21/11/17.
//

#include "WebService.h"

#include <Print.h>

WebService::WebService(Print& out, int16_t port) :
    out(out),
    ESP8266WebServer(port)
{
}

void WebService::init()
{
    begin();
    WebService* that = this;
    on("/", [that]()
    {
        digitalWrite(BUILTIN_LED, false);
        that->out.println("http request /");
        that->send(200, "text/plain", "response to http request \"/\"");
        digitalWrite(BUILTIN_LED, true);
    });

    on("/index.html", [that]()
    {
        digitalWrite(BUILTIN_LED, false);
        that->out.println("http request /index.html");
        that->send(200, "text/plain", "response to http request \"/index.html\"");
        digitalWrite(BUILTIN_LED, true);
    });
}
