#include "colour.h"

//COLOUR 
Colour::Colour() {
    _r = 0;
    _g = 0;
    _b = 0;
    _a = 1;
}
Colour::Colour (uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

uint8_t& Colour::r()
{
    return _r;
}

uint8_t& Colour::g()
{
    return _g;
}

uint8_t& Colour::b()
{
    return _b;
}

uint8_t& Colour::a()
{
    return _a;
}

uint8_t Colour::r() const
{
    return _r;
}

uint8_t Colour::g() const
{
    return _g;
}

uint8_t Colour::b() const
{
    return _b;
}

uint8_t Colour::a() const
{
    return _a;
}

Colour Colour::operator+ (Colour c)
{
    return Colour (_r + c._r, _g + c._g, _b + c._b);
}


//FLOAT COLOUR
fColour::fColour(){
    _r = 0.;
    _g = 0.;
    _b = 0.;
    _a = 1.;
}
fColour::fColour (float r, float g, float b, float a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

float& fColour::r()
{
    return _r;
}

float& fColour::g()
{
    return _g;
}

float& fColour::b()
{
    return _b;
}

float& fColour::a()
{
    return _a;
}

float fColour::r() const
{
    return _r;
}

float fColour::g() const
{
    return _g;
}

float fColour::b() const
{
    return _b;
}

float fColour::a() const
{
    return _a;
}

fColour fColour::operator+ (fColour c)
{
    return fColour (_r + c._r, _g + c._g, _b + c._b);
}

