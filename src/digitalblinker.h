#ifndef DIGITALBLINKER_H
#define DIGITALBLINKER_H

#include <Arduino.h>
class digital
{
public:
    void init(uint8_t _led1, uint8_t _led2, uint32_t blinkzeit, bool enable);
    void poll();

private:
    uint8_t led1, led2;
    unsigned long lastblink;
    bool Aktiv;
    uint32_t time;
};

#endif