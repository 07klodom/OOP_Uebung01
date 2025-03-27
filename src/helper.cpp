#include <Arduino.h>
#include "helper.h"

void db::init(uint8_t _taster, uint8_t _db_zeit, bool _inv)
{
  taster = _taster;
  db_zeit = _db_zeit;
  inv = _inv;
}

void db::poll()
{
  in = digitalRead(taster);
  in = inv ? !in : in;

  if (millis() - last > db_zeit) // Nutzt die einstellbare Entprellzeit
  {
    if (in == vorher) // Wenn sich der Taster stabilisiert hat
    {
      out = in;
    }
    last = millis();
    vorher = in;
  }
}

void flanke::init(bool &_input)
{
  input = &_input;
}

void flanke::poll()
{
  in = *input;

  pos = (!vorher && in); // positive Flanke
  neg = (vorher && !in); // negative Flanke

  if (pos)
  {
    zeit = millis();
  }

  lang = false;
  kurz = false;

  if (neg)
  {
    uint32_t dauer = millis() - zeit;
    if (dauer >= 1000)
    {
      lang = true;
    }
    else
    {
      kurz = true;
    }
  }

  vorher = in;
}
