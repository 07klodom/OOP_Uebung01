#include <Arduino.h>
#include "analogblinker.h"

void blinken::init(uint8_t _led1, uint8_t _led2, uint8_t _POTI, bool enable_)
{
    led1 = _led1;
    led2 = _led2;
    POTI = _POTI;
    enable = enable_;
    last = millis();
    hell = 0;
    hell2 = 255;
    state = 5;
    state2 = 5;
}

void blinken::poll()
{
    if (enable)
    {
        uint64_t poti = analogRead(POTI);
        uint64_t blinkInterval = map(poti, 0, 1023, 50, 1000);
        
        if (millis() - last >= blinkInterval)
        {
            last = millis();
            analogWrite(led1, hell);
            analogWrite(led2, hell2);
            hell += state;
            hell2 -= state2;
            if (hell >= 255 || hell <= 0) state = -state;
            if (hell2 >= 255 || hell2 <= 0) state2 = -state2;
        }
    }
    else
    {
        analogWrite(led1, 0);
        analogWrite(led2, 0);
    }
}