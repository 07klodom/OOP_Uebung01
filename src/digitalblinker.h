#ifndef DIGITALBLINKER_H
#define DIGITALBLINKER_H

#include <Arduino.h>
class digital
{
    uint8_t led1, led2;
    unsigned long lastblink;
    bool Aktiv;
    uint32_t time;

    void init(uint8_t _led1, uint8_t _led2,uint32_t blinkzeit, bool enable);
    void poll();
};

#endif