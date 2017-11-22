//
// Created by rubienr on 21/11/17.
//

#include "WebService.h"

#include <ESP8266mDNS.h>
#include <FS.h>

WebService::WebService(Print& out, int16_t port) :
    out(out),
    ESP8266WebServer(port),
    updateServer(),
    mdns(MDNS)
{
}

void WebService::init()
{
    mdns.begin("the-office-gadget");
    updateServer.setup(this);
    begin();
    MDNS.addService("http", "tcp", 80);

    WebService* that = this;
    on("/", [that]()
    {
        digitalWrite(BUILTIN_LED, 0);
        that->out.println("http request /");
        that->send(200, "text/plain", "response to http request \"/\"");
        digitalWrite(BUILTIN_LED, 1);
    });

    on("/index.html", [that]()
    {
        digitalWrite(BUILTIN_LED, 0);
        that->out.println("http request /index.html");
        that->send(200, "text/plain", "response to http request \"/index.html\"");
        digitalWrite(BUILTIN_LED, 1);
    });

    on("/files", [that]()
    {
        digitalWrite(BUILTIN_LED, 0);
        Dir    dir = SPIFFS.openDir("");
        String fileListing;
        while (dir.next())
        {
            File f = dir.openFile("r");
            fileListing.concat("name" + dir.fileName() + " size " + f.size() + "\n");
            f.close();
        }
        that->send(200, "text/plain", fileListing);
        digitalWrite(BUILTIN_LED, 1);
    });
}
