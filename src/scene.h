#pragma once

#include <vector>
#include "shape.h"
#include "lightSources.h"
#include "colour.h"
#include "hit.h"

class Scene
{
    public:
        Scene();
        void setBackgroundColour(const Colour& newColour);
        void addShape (Shape* shape);
        void addLightSource(LightSource* lightSource);
        Colour castRay(const Ray& ray) const;

    private:
        Colour _bgColour;
        std::vector<Shape*> _shapes;
        std::vector<LightSource*> _lightSources;
};