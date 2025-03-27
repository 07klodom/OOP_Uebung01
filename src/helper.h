#ifndef HELPER_H
#define HELPER_H

#include <Arduino.h>
struct db
{
    bool vorher, out, in, inv;
    unsigned long last = 0;
    uint8_t taster = 0;
    uint8_t db_zeit = 0;

    void init(uint8_t, uint8_t, bool);

    void poll();
};
struct flanke
{
public:
    bool vorher, out, in, pos, neg, lang;
    bool *input;

private:
    unsigned long zeit = 0;

    void init(bool &);

    void poll();
};

#endif