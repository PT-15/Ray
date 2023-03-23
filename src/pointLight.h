#pragma once

#include "lightSources.h"

class PointLight: public LightSource
{
    public:
        PointLight ();
        PointLight (Vec3f position, fColour colour, float intensity);

        virtual Vec3f getDir(const Vec3f& position) const;

    private:
};

/*
INHERITED FROM LIGHTSOURCES

Vec3f _pos;
fColour _colour;
float _intensity;

Vec3f pos();
void setPos(float x, float y, float z);
fColour colour();
void setColour(float r, float g, float b, float a = 1.);
float intensity();
void setIntensity(float intensity);
*/