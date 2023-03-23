#pragma once

#include "material.h"
#include "lightSources.h"

class Lambert: public Material
{
    public:
        Lambert();
        Lambert(fColour colour);
    
        virtual fColour shade(const LightSource& light, const Hit& hit) const;
};

/*
INHERITED:
fColour _colour

fColour getColour();
void setColour(float r, float g, float b, float a = 1.);
*/