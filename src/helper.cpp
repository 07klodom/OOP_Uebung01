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
  in = inv ? !in : in; // ternary

  out = vorher;
  if (millis() - last > 500)
  {
    if (in != vorher)
    {
      out = vorher;
    }
    else
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
  in = *input; // derfernwier.operator * greift auf den Inahlt der speicherzelle zu, auf die der pointer zeigt

  pos = false;
  if (in && !vorher)
    pos = true;

  neg = false;
  if (!in && vorher)
    neg = true;

    lang = false;
    kurz = false;

    if (pos == true)
    {
        zeit = millis();
    }
    if(neg == true)
    {
       if(millis() - zeit >= 1000)
       {
        lang = true;
       }
       else if(millis() - zeit <= 1000)
       {
        kurz = true;
       }
    }

  vorher = in;
}