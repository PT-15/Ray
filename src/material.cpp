#include "material.h"

Material::Material()
{}

Material::Material(fColour colour):
    _colour(colour)
{}

fColour Material::getColour() const
{
    return _colour;
}

void Material::setColour(float r, float g, float b, float a)
{
    _colour.r() = r;
    _colour.g() = g;
    _colour.b() = b;
    _colour.a() = a;
}