#include "pointLight.h"

PointLight::PointLight(){}
PointLight::PointLight(Vec3f position, fColour colour, float intensity):
    LightSource(position, colour, intensity)
{}

Vec3f PointLight::getDir(const Vec3f& position) const
{
    return (_pos - position).getNormalized();
}
