#include "lightSources.h"

LightSource::LightSource(){}
LightSource::LightSource (Vec3f position, fColour colour, float intensity):
    _pos(position),
    _colour(colour),
    _intensity(intensity)
{}

Vec3f LightSource::pos() const
{
    return _pos;
}

void LightSource::setPos(float x, float y, float z)
{
    _pos.x() = x;
    _pos.y() = y;
    _pos.z() = z;
}

fColour LightSource::colour() const
{
    return _colour;
}

void LightSource::setColour(float r, float g, float b, float a)
{
    _colour.r() = r;
    _colour.g() = g;    
    _colour.b() = b;
    _colour.a() = a;
}

float LightSource::intensity() const
{
    return _intensity;
}

void LightSource::setIntensity(float intensity)
{
    _intensity = intensity;
}
