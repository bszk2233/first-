#include "Arduino.h"
#include "morsecode.h"



MorseCode::MorseCode(int pin, int delaytime)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
    _delaytime = delaytime;
}

void MorseCode::dot()
{
    digitalWrite(_pin, HIGH);
    delay(_delaytime);
    digitalWrite(_pin, LOW);
    delay(_delaytime);
}

void MorseCode::dash()
{
    digitalWrite(_pin, HIGH);
    delay(_delaytime * 3);
    digitalWrite(_pin, LOW);
    delay(_delaytime);
}

void MorseCode::divid()
{
    digitalWrite(_pin, LOW);
    delay(_delaytime * 3);
}

void MorseCode::space()
{
    digitalWrite(_pin, LOW);
    delay(_delaytime * 7);
}
