#pragma once

#include "shape.h"

class Sphere: public Shape
{
    public:
        Sphere(const Vec3f& center, float radius);
        Hit closestIntersect(const Ray& ray);

    private:
        Vec3f _center;
        float _r;
};