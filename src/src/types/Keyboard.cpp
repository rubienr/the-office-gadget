//
// Created by rubienr on 08/11/17.
//

#include "Keyboard.h"
#include "Ressources.h"

extern Ressources r;

const uint16_t Keyboard::OnHoldDurationMs = 50git 0;
const uint16_t Keyboard::OnHoldRepeatMs   = 250;

ButtonCallback::~ButtonCallback()
{
}

ButtonEventConsumer::ButtonEventConsumer() :
    buttonPressed(0),
    buttonReleased(0),
    buttonRepeated(0),
    buttonMask(0),
    buttonElapsedTime(0),
    buttonEventCount(0)
{
}

ButtonEventConsumer::~ButtonEventConsumer()
{
}

void ButtonEventConsumer::onPress(uint8_t buttonId)
{
    buttonPressed = buttonId;
}

void ButtonEventConsumer::onRelease(uint8_t buttonId, uint16_t elapsedTime)
{
    buttonReleased    = buttonId;
    buttonElapsedTime = elapsedTime;
}

void ButtonEventConsumer::onRepeat(uint8_t buttonId, uint16_t elapsedTime, uint16_t repeatCount)
{
    buttonRepeated    = buttonId;
    buttonElapsedTime = elapsedTime;
    buttonEventCount  = repeatCount;
}

Keyboard::Keyboard(const I2cBus& i2cBus) :
    buttonCb0(*this, 0),
    buttonCb1(*this, 1),
    buttonCb2(*this, 2),
    buttonCb3(*this, 3),
    buttonCb4(*this, 4),
    buttonCb5(*this, 5),
    buttonCb6(*this, 6),
    buttonCb7(*this, 7),
    buttonCb8(*this, 8),
    buttonCb9(*this, 9),
    buttonCb10(*this, 10),
    buttonCb11(*this, 11),
    buttonCb12(*this, 12),
    i2cAddress(0x5b),
    i2cBus(i2cBus),
    button0(0, *this),
    button1(1, *this),
    button2(2, *this),
    button3(3, *this),
    button4(4, *this),
    button5(5, *this),
    button6(6, *this),
    button7(7, *this),
    button8(8, *this),
    button9(9, *this),
    button10(10, *this),
    button11(11, *this),
    button12(12, *this)
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::init()
{
    begin(i2cAddress);

    buttonCb0.onPress(onButton0press);
    buttonCb1.onPress(onButton1press);
    buttonCb2.onPress(onButton2press);
    buttonCb3.onPress(onButton3press);
    buttonCb4.onPress(onButton4press);
    buttonCb5.onPress(onButton5press);
    buttonCb6.onPress(onButton6press);
    buttonCb7.onPress(onButton7press);
    buttonCb8.onPress(onButton8press);
    buttonCb9.onPress(onButton9press);
    buttonCb10.onPress(onButton10press);
    buttonCb11.onPress(onButton11press);
    buttonCb12.onPress(onButton12press);

    buttonCb0.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton0repeat);
    buttonCb1.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton1repeat);
    buttonCb2.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton2repeat);
    buttonCb3.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton3repeat);
    buttonCb4.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton4repeat);
    buttonCb5.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton5repeat);
    buttonCb6.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton6repeat);
    buttonCb7.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton7repeat);
    buttonCb8.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton8repeat);
    buttonCb9.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton9repeat);
    buttonCb10.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton10repeat);
    buttonCb11.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton11repeat);
    buttonCb12.onHoldRepeat(Keyboard::OnHoldDurationMs, Keyboard::OnHoldRepeatMs, onButton12repeat);

    buttonCb0.onRelease(onButton0release);
    buttonCb1.onRelease(onButton1release);
    buttonCb2.onRelease(onButton2release);
    buttonCb3.onRelease(onButton3release);
    buttonCb4.onRelease(onButton4release);
    buttonCb5.onRelease(onButton5release);
    buttonCb6.onRelease(onButton6release);
    buttonCb7.onRelease(onButton7release);
    buttonCb8.onRelease(onButton8release);
    buttonCb9.onRelease(onButton9release);
    buttonCb10.onRelease(onButton10release);
    buttonCb11.onRelease(onButton11release);
    buttonCb12.onRelease(onButton12release);
}

void Keyboard::update()
{
    buttonCb0.update();
    buttonCb1.update();
    buttonCb2.update();
    buttonCb3.update();
    buttonCb4.update();
    buttonCb5.update();
    buttonCb6.update();
    buttonCb7.update();
    buttonCb8.update();
    buttonCb9.update();
    buttonCb10.update();
    buttonCb11.update();
    buttonCb12.update();
}

void ButtonCallback::onPress()
{
}

void ButtonCallback::onRelease(uint16_t elapsedTime)
{
}

void ButtonCallback::onRepeat(uint16_t elapsedTime, uint16_t repeatCount)
{
}

void onButton0press(Button&)
{
    r.keyboard.button0.onPress();
}

void onButton0repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button0.onRepeat(elapsedTime, repeatCount);
}

void onButton0release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button0.onRelease(elapsedTime);
}

void onButton1press(Button&)
{
    r.keyboard.button1.onPress();
}

void onButton1repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button1.onRepeat(elapsedTime, repeatCount);
}

void onButton1release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button1.onRelease(elapsedTime);
}

void onButton2press(Button&)
{
    r.keyboard.button2.onPress();
}

void onButton2repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button2.onRepeat(elapsedTime, repeatCount);
}

void onButton2release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button2.onRelease(elapsedTime);
}

void onButton3press(Button&)
{
    r.keyboard.button3.onPress();
}

void onButton3repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button3.onRepeat(elapsedTime, repeatCount);
}

void onButton3release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button3.onRelease(elapsedTime);
}

void onButton4press(Button&)
{
    r.keyboard.button4.onPress();
}

void onButton4repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button4.onRepeat(elapsedTime, repeatCount);
}

void onButton4release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button4.onRelease(elapsedTime);
}

void onButton5press(Button&)
{
    r.keyboard.button5.onPress();
}

void onButton5repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button5.onRepeat(elapsedTime, repeatCount);
}

void onButton5release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button5.onRelease(elapsedTime);
}

void onButton6press(Button&)
{
    r.keyboard.button6.onPress();
}

void onButton6repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button6.onRepeat(elapsedTime, repeatCount);
}

void onButton6release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button6.onRelease(elapsedTime);
}

void onButton7press(Button&)
{
    r.keyboard.button7.onPress();
}

void onButton7repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button7.onRepeat(elapsedTime, repeatCount);
}

void onButton7release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button7.onRelease(elapsedTime);
}

void onButton8press(Button&)
{
    r.keyboard.button8.onPress();
}

void onButton8repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button8.onRepeat(elapsedTime, repeatCount);
}

void onButton8release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button8.onRelease(elapsedTime);
}

void onButton9press(Button&)
{
    r.keyboard.button9.onPress();
}

void onButton9repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button9.onRepeat(elapsedTime, repeatCount);
}

void onButton9release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button9.onRelease(elapsedTime);
}

void onButton10press(Button&)
{
    r.keyboard.button10.onPress();
}

void onButton10repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button10.onRepeat(elapsedTime, repeatCount);
}

void onButton10release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button10.onRelease(elapsedTime);
}

void onButton11press(Button&)
{
    r.keyboard.button11.onPress();
}

void onButton11repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button11.onRepeat(elapsedTime, repeatCount);
}

void onButton11release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button11.onRelease(elapsedTime);
}

void onButton12press(Button&)
{
    r.keyboard.button12.onPress();
}

void onButton12repeat(Button& btn, uint16_t elapsedTime, uint16_t repeatCount)
{
    r.keyboard.button12.onRepeat(elapsedTime, repeatCount);
}

void onButton12release(Button& btn, uint16_t elapsedTime)
{
    r.keyboard.button12.onRelease(elapsedTime);
}
