#pragma once

#include <iostream>

class Colour
{
    public:
        Colour();
        Colour (uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
        uint8_t& r();
        uint8_t& g();
        uint8_t& b();
        uint8_t& a();
        uint8_t r() const;
        uint8_t g() const;
        uint8_t b() const;
        uint8_t a() const;
        
        Colour operator+ (Colour c);

    private:
        uint8_t _r;
        uint8_t _g;
        uint8_t _b;
        uint8_t _a;
};

class fColour
{
    public:
        fColour();
        fColour (float r, float g, float b, float a = 1.);
        float& r();
        float& g();
        float& b();
        float& a();
        float r() const;
        float g() const;
        float b() const;
        float a() const;

        fColour operator+ (fColour c);

    private:
        float _r;
        float _g;
        float _b;
        float _a;
};