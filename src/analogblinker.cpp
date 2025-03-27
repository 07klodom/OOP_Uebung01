#include <Arduino.h>
#include "analogblinker.h"

void blinken::init(uint8_t _led1, uint8_t _led2, uint8_t _POTI, bool enable_)
{
    led1 = _led1;
    led2 = _led2;
    POTI = _POTI;
    enable = enable_;
}

void blinken::poll()
{
    uint64_t poti = analogRead(POTI);
    uint64_t blinkInterval = (100 + (poti * 2900) / 1023) / 51;
    if (enable)
    {
        if (millis() - last >= blinkInterval)
        {
            last = millis();
            analogWrite(led1, hell);
            
            hell += state;
            if (hell >= 255)
            {
                hell = 255;
                state = -state;
            }
            else if (hell <= 0)
            {
                hell = 0;
                state = -state;
            }

            analogWrite(led2, hell2);
            hell2 -= state2;
            if (hell2 >= 255)
            {
                hell2 = 255;
                state2 = -state2;
            }
            else if (hell2 <= 0)
            {
                hell2 = 0;
                state2 = -state2;
            }
        }
    }
    else
    {
        analogWrite(led1, 0);
        analogWrite(led2, 0);
    }
}