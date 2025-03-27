#include <Arduino.h>
#include <analogblinker.h>
#include <digitalblinker.h>
#include <helper.h>
#define LED1 8
#define LED2 7
#define TASTER1 3
#define TASTER2 2
#define POT1 A7
#define DB_ZEIT 5

uint32_t blinktime;
blinken analog;
digital blink;
db db_taster1;
db db_taster2;
flanke fp_taster1;
flanke fp_taster2;
bool enable, denable;

void setup()
{
    pinMode(TASTER1, INPUT_PULLUP);
    pinMode(TASTER2, INPUT_PULLUP);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    
    enable = false;
    denable = false;
    blinktime = 500;
    
    analog.init(LED1, LED2, POT1, enable);
    blink.init(LED1, LED2, blinktime, denable);
    db_taster1.init(TASTER1, DB_ZEIT, false);
    db_taster2.init(TASTER2, DB_ZEIT, true);
    fp_taster1.init(db_taster1.out);
    fp_taster2.init(db_taster2.out);
}

void loop()
{
    db_taster1.poll();
    db_taster2.poll();
    fp_taster1.poll();
    fp_taster2.poll();

    if(fp_taster1.lang || fp_taster2.lang)
    {
        enable = !enable;
        denable = !denable;
    }
    else if(fp_taster1.kurz)
    {
        enable = true;
        denable = false;
    }
    else if(fp_taster2.kurz)
    {
        enable = false;
        denable = true;
    }

    if (denable)
    {
        blink.poll();
    }
    else if (enable)
    {
        analog.poll();
    }
}