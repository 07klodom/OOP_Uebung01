#ifndef ANALONGBLINKER_H
#define ANALONGBLINKER_H

#include <Arduino.h>
#include <Arduino.h>

class blinken
{
public:
    uint64_t blinken;

    void init(uint8_t led1, uint8_t led2, uint8_t, bool enable_);
    void poll();

private:
    uint64_t POTI;
    bool enable;
    uint8_t led1, led2;
    unsigned long last;
    uint16_t state = 5, hell;
    uint16_t state2 = 5, hell2 = 255;
};

#endif