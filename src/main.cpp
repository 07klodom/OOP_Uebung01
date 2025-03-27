
// ****************************************************************************
// *                                                                          *
// * Aufgabe:                                                                 *
// *                                                                          *
// * -> Schreib ein Programm mit folgenden Eigenschaften:                     *
// *    Es gibt zwei Taster (TASTER1, TASTER2), zwei LEDs (LED1, LED2) und    *
// *    ein Potentiometer. Taster1 schaltet einen digitalen Blinker auf die   *
// *    beiden LEDs, Taster2 schaltet einen analogen Blinker auf die beiden   *
// *    LEDs. Die Geschwindigkeit des Blinkers soll mit dem Poti zwischen     *
// *    50ms und 1000ms eingestellt werden können. Ein langer Tastendruck     *
// *    auf einen der beiden Taster toggelt die Blinkfunktion ein/aus.        *
// *                                                                          *
// * -> Suche dir ein/zwei Mitarbeiter und forke dieses Projekt               *
// * -> Teile die Arbeit auf die Mitarbeiter so auf, dass ein fast-forward-   *
// *    merge ermöglicht wird.                                                *
// * -> Fülle die bestehenden Header-Dateien und erzeuge die entsprechenden   *
// *    Implementierungen (cpp-Dateien). Verwende ausschließlich Klassen!     *
// *                                                                          *
// * -> Erstelle einen pull-request                                           *
// *                                                                          *
// *                                                                          *
// ****************************************************************************

#include <Arduino.h>
#include <analogblinker.h>
#include <digitalblinker.h>
#include <helper.h>
#define LED1 8    // Low-side switch (leuchtet mit LOW)
#define LED2 7    // Low-side switch (leuchtet mit LOW)
#define TASTER1 3 // LOW wenn gedrückt
#define TASTER2 2 // LOW wenn gedrückt
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
    Serial.begin(115200); // Baud rate
    Serial.println("..Start..\n");
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
    analog.poll();
    blink.poll();
    if(fp_taster1.lang || fp_taster2.lang)
    {
        enable = 0;
        denable = 0;
    }
    if(fp_taster1.kurz)
    {
        enable = 1;
        denable = 0;
    }
    if(fp_taster2.kurz)
    {
        enable = 0;
        denable = 1;
    }

}
