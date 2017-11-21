//
// Created by rubienr on 08/11/17.
//

#pragma once

#include <Button.h>

typedef Button PerfectExampleOnHowToNotRapeCPP;

#include <ButtonEventCallback.h>
#include <MPR121Button.h>

typedef MPR121Button NextFishyCandidate;

#include <Adafruit_MPR121.h>
#include "../ressources/I2cBusConfig.h"

class ButtonCallback
{
private:

protected:

public:
    virtual ~ButtonCallback();
    virtual void onPress() = 0;
    virtual void onRelease(uint16_t elapsedTime) = 0;
    virtual void onRepeat(uint16_t elapsedTime, uint16_t repeatCount) = 0;
};

class ButtonEventConsumer
{
private:

public:
    uint8_t  buttonPressed;
    uint8_t  buttonReleased;
    uint8_t  buttonRepeated;
    uint8_t  buttonMask;
    uint16_t buttonElapsedTime;
    uint16_t buttonEventCount;

protected:

public:
    ButtonEventConsumer();
    virtual ~ButtonEventConsumer();
    void onPress(uint8_t buttonId);
    void onRelease(uint8_t buttonId, uint16_t elapsedTime);
    void onRepeat(uint8_t buttonId, uint16_t elapsedTime, uint16_t repeatCount);
};

class ButtonEventProxy : public ButtonCallback
{
protected:
private:
    ButtonEventConsumer& eventConsumer;
    uint8_t buttonId;
public:

    virtual ~ButtonEventProxy()
    {
    }

    ButtonEventProxy(uint8_t buttonId, ButtonEventConsumer& eventConsumer) :
        eventConsumer(eventConsumer),
        buttonId(buttonId)
    {
    }

    virtual void onPress()
    {
        eventConsumer.onPress(buttonId);
    }

    virtual void onRelease(uint16_t elapsedTime)
    {
        eventConsumer.onRelease(buttonId, elapsedTime);
    }

    virtual void onRepeat(uint16_t elapsedTime, uint16_t repeatCount)
    {
        eventConsumer.onRepeat(buttonId, elapsedTime, repeatCount);
    }
};

class Keyboard : public Adafruit_MPR121, public ButtonEventConsumer
{
protected:

private:
    MPR121Button buttonCb0;
    MPR121Button buttonCb1;
    MPR121Button buttonCb2;
    MPR121Button buttonCb3;
    MPR121Button buttonCb4;
    MPR121Button buttonCb5;
    MPR121Button buttonCb6;
    MPR121Button buttonCb7;
    MPR121Button buttonCb8;
    MPR121Button buttonCb9;
    MPR121Button buttonCb10;
    MPR121Button buttonCb11;
    MPR121Button buttonCb12;

    static const uint16_t OnHoldDurationMs;
    static const uint16_t OnHoldRepeatMs;

public:
    const uint8_t i2cAddress;
    const I2cBusConfig& i2cBus;

    ButtonEventProxy button0;
    ButtonEventProxy button1;
    ButtonEventProxy button2;
    ButtonEventProxy button3;
    ButtonEventProxy button4;
    ButtonEventProxy button5;
    ButtonEventProxy button6;
    ButtonEventProxy button7;
    ButtonEventProxy button8;
    ButtonEventProxy button9;
    ButtonEventProxy button10;
    ButtonEventProxy button11;
    ButtonEventProxy button12;

    Keyboard(const I2cBusConfig& i2cBus);
    virtual ~Keyboard();
    void init();
    void update();
};

void onButton0press(Button& btn);
void onButton1press(Button& btn);
void onButton2press(Button& btn);
void onButton3press(Button& btn);
void onButton4press(Button& btn);
void onButton5press(Button& btn);
void onButton6press(Button& btn);
void onButton7press(Button& btn);
void onButton8press(Button& btn);
void onButton9press(Button& btn);
void onButton10press(Button& btn);
void onButton11press(Button& btn);
void onButton12press(Button& btn);

void onButton0repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton1repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton2repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton3repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton4repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton5repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton6repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton7repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton8repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton9repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton10repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton11repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);
void onButton12repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount);

void onButton0release(Button& btn, uint16_t elapsedTime);
void onButton1release(Button& btn, uint16_t elapsedTime);
void onButton2release(Button& btn, uint16_t elapsedTime);
void onButton3release(Button& btn, uint16_t elapsedTime);
void onButton4release(Button& btn, uint16_t elapsedTime);
void onButton5release(Button& btn, uint16_t elapsedTime);
void onButton6release(Button& btn, uint16_t elapsedTime);
void onButton7release(Button& btn, uint16_t elapsedTime);
void onButton8release(Button& btn, uint16_t elapsedTime);
void onButton9release(Button& btn, uint16_t elapsedTime);
void onButton10release(Button& btn, uint16_t elapsedTime);
void onButton11release(Button& btn, uint16_t elapsedTime);
void onButton12release(Button& btn, uint16_t elapsedTime);
