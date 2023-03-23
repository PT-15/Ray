#pragma once

#include "vector.h"
#include "colour.h"

class LightSource
{
    public:
        LightSource ();
        LightSource (Vec3f position, fColour colour, float intensity);

        Vec3f pos() const;
        void setPos(float x, float y, float z);
        fColour colour() const;
        void setColour(float r, float g, float b, float a = 1.);
        float intensity() const;
        void setIntensity(float intensity);

        virtual Vec3f getDir (const Vec3f& position) const = 0;

    protected:
        Vec3f _pos;
        fColour _colour;
        float _intensity;
};