#include "lambert.h"

Lambert::Lambert()
{}

Lambert::Lambert(fColour colour):
    Material(colour)
{}

fColour Lambert::shade(const LightSource& light, const Hit& hit) const
{
    Vec3f lightDir = light.getDir(hit.pos);

    //Calculate shades

    //Calculate cos of the angle between the light vector and the normal
    float cosA = hit.n.dot(lightDir);
    if (cosA < 0.)
        cosA = 0.;

    float r = _colour.r() * light.colour().r() * light.intensity() * cosA;
    float g = _colour.g() * light.colour().g() * light.intensity() * cosA;
    float b = _colour.b() * light.colour().b() * light.intensity() * cosA;
    
    return fColour(r, g, b);
}
