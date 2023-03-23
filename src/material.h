#pragma once

#include "colour.h"
#include "ray.h"
#include "hit.h"
#include "pointLight.h"

class Material
{
    public:
        Material();
        Material(fColour colour);

        fColour getColour() const;
        void setColour(float r, float g, float b, float a = 1.);

        virtual fColour shade(const LightSource& light, const Hit& hit) const = 0;

    protected:
        fColour _colour;
};