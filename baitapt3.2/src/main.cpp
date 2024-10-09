#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

int control = 0;

LED led[2] = {
    LED(LED_PIN, LED_ACT),
    LED(LED_PIN2, LED_ACT),
};

void btnPush();
void btnHold();
void btndbclick();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{ 
    led[0].off();
    led[1].off();
    button.attachClick(btnPush);
    button.attachDoubleClick(btndbclick);
    button.attachLongPressStart(btnHold);
}

void loop()
{
    led[0].loop();
    led[1].loop();
    button.tick();
}

void btnPush()
{
    led[control].flip();
}

void btnHold()
{
    led[control].blink(200);
}

void btndbclick(){
    control = (control+1) % 2;
}