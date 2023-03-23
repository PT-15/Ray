#include "scene.h"
#include "material.h"

Scene::Scene():
    _bgColour(0, 0, 0, 0)
{}

void Scene::setBackgroundColour(const Colour& newColour)
{
    _bgColour = newColour;
}

void Scene::addShape (Shape* shape)
{
    _shapes.push_back(shape);
}

void Scene::addLightSource (LightSource* lightSource)
{
    _lightSources.push_back(lightSource);
}

Colour Scene::castRay (const Ray& ray) const
{
    Colour pixelColour = _bgColour;

    bool hitFound = false;
    Hit closestHit;

    for (int i = 0; i < (int)_shapes.size(); i++){
        Hit tmp = _shapes[i]->closestIntersect(ray);

        if (!tmp.wasHit)
            continue;

        if (!hitFound){
            closestHit = tmp;
            hitFound = true;
            continue;
        }

        if ((tmp.pos - ray.pos).module() < (closestHit.pos - ray.pos).module()){
            closestHit = tmp;
        }
    }

    if (hitFound){
        Material* surfaceMaterial = closestHit.collisionObject->getMaterial();

        fColour shadeColour;
        for (int i = 0; i < (int)_lightSources.size(); i++){
            fColour shapeC = surfaceMaterial->shade(*(_lightSources[i]), closestHit);
            shadeColour = shadeColour + shapeC;
        }

        //Check if it goes over 1
        if (shadeColour.r() > 1.)
            shadeColour.r() = 1.;
        if (shadeColour.g() > 1.)
            shadeColour.g() = 1.;
        if (shadeColour.b() > 1.)
            shadeColour.b() = 1.;
        if (shadeColour.a() > 1.)
            shadeColour.a() = 1.;

        //Transform to 0-255 int colour
        pixelColour.r() = shadeColour.r() * 255;
        pixelColour.g() = shadeColour.g() * 255;
        pixelColour.b() = shadeColour.b() * 255;
    }

    return pixelColour;
}
