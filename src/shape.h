#pragma once

#include "hit.h"
#include "ray.h"
#include "material.h"

class Shape
{
    public:
        Shape();
        Shape(Material *material);

        Material* getMaterial() const;
        void setMaterial(Material* newMaterial);

        virtual Hit closestIntersect(const Ray& ray) = 0;

    protected:
        Material* _material;
};