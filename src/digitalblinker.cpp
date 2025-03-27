#include "digitalblinker.h"
#include <Arduino.h>

void digital::init(uint8_t _led1, uint8_t _led2, uint32_t blinkzeit, bool enable)
{
    led1 = _led1;
    led2 = _led2;
    Aktiv = enable;
    time = blinkzeit;
    lastblink = millis();
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
}

void digital::poll()
{
    if (Aktiv)
    {
        if (millis() - lastblink >= time)
        {
            bool currentState = digitalRead(led1);
            digitalWrite(led1, !currentState);
            digitalWrite(led2, currentState);
            lastblink = millis();
        }
    }
    else
    {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
    }
}