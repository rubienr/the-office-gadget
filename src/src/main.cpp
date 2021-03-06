//
// Created by rubienr on 08/11/17.
//

#include "ressources/Resources.h"
#include "config/WifiConfig.hpp"

Resources r;


// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 55, suggested range 20-100
#define COOLING  55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 120
bool gReverseDirection = false;

CRGBPalette16 gPal = HeatColors_p;

void Fire2012WithPalette()
{
// Array of temperature readings at each simulation cell
    const uint8_t ledsCount = sizeof(r.ledStrip.leds) / sizeof(CRGB);
    static byte   heat[ledsCount];

    // Step 1.  Cool down every cell a little
    for (int i = 0; i < ledsCount; i++)
    {
        heat[i] = qsub8(heat[i], random8(0, ((COOLING * 10) / ledsCount) + 2));
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for (int k = ledsCount - 1; k >= 2; k--)
    {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if (random8() < SPARKING)
    {
        int y = random8(7);
        heat[y] = qadd8(heat[y], random8(160, 255));
    }

    // Step 4.  Map from heat cells to LED colors
    for (int j = 0; j < ledsCount; j++)
    {
        // Scale the heat value from 0-255 down to 0-240
        // for best results with color palettes.
        byte colorindex = scale8(heat[j], 240);
        CRGB color      = ColorFromPalette(gPal, colorindex);
        int  pixelnumber;
        if (gReverseDirection)
        {
            pixelnumber = (ledsCount - 1) - j;
        }
        else
        {
            pixelnumber = j;
        }
        r.ledStrip.leds[pixelnumber] = color;
    }
}

void setup()
{
    ESP.wdtDisable();
    r.init();
    ESP.wdtEnable(0);
}

void loop()
{
    Serial.println("loop");
    Fire2012WithPalette();
    r.ledStrip.fastLED.show();
    r.sensors.measureTemperature();
    r.keyboard.update();
    r.displays.display0.clear();

    WifiConfiguration::Data wifiConfig;

    WifiConfiguration::Enabled     & en    = wifiConfig.data.getField<WifiConfiguration::Enabled>();
    WifiConfiguration::Ssid        & ssid  = wifiConfig.data.getField<WifiConfiguration::Ssid>();
    WifiConfiguration::Password    & pwd   = wifiConfig.data.getField<WifiConfiguration::Password>();
    WifiConfiguration::TimeoutMs   & toMs  = wifiConfig.data.getField<WifiConfiguration::TimeoutMs>();
    WifiConfiguration::ConnectRetry& retry = wifiConfig.data.getField<WifiConfiguration::ConnectRetry>();

    en.value    = true;
    ssid.value  = "diss";
    pwd.value   = "drowssap";
    toMs.value  = 42;
    retry.value = 7;
    wifiConfig.toJson();

    en.value    = false;
    ssid.value  = "0xDEADBEEF";
    pwd.value   = "0xB00BS";
    toMs.value  = 0;
    retry.value = 0;
    wifiConfig.fromJson();

    r.displays.display0.printf("The Gadget! it=%d en=%d\n", WifiConfiguration::Data::itemsCount(), en.value);
    r.displays.display0.printf("%s = %s\n", ssid.name.c_str(), ssid.value.c_str()); // expect "diss"
    r.displays.display0.printf("%s = %s\n", pwd.name.c_str(), pwd.value.c_str());   // expect "drowssap"
    r.displays.display0.printf("%s = %d\n", toMs.name.c_str(), toMs.value);         // expect 42
    r.displays.display0.printf("%s = %d\n", retry.name.c_str(), retry.value);       // expect 7
    r.displays.display0.displayBuffer();

    /*
    r.displays.display0.printf("The gadget! t=%d i=%d u=%d\n", t.itemsCount(), 0,0);
    r.displays.display0.print("temperature ");
    r.displays.display0.print(r.sensors.getTemperature());
    r.displays.display0.print("°C\n");
    r.displays.display0.print("lux: ");
    r.displays.display0.print(r.sensors.currentLux());
    r.displays.display0.printf("\nip-addr: %s\n", WiFi.localIP().toString().c_str());
    r.wifi.printConnectstatus(WiFi.status(), r.displays.display0);
    r.displays.display0.displayBuffer();
    */

    r.displays.display1.clear();
    r.displays.display1.print("Keyboard Events\n");
    r.displays.display1.printf("pressed  %d\n", r.keyboard.buttonPressed);
    r.displays.display1.printf("released %d\n", r.keyboard.buttonReleased);
    r.displays.display1.printf("repeated %d\n", r.keyboard.buttonRepeated);
    r.displays.display1.printf("delay    %d count %d\n",
                               r.keyboard.buttonElapsedTime,
                               r.keyboard.buttonEventCount);
    r.displays.display1.displayBuffer();

    r.webService.handleClient();
}
