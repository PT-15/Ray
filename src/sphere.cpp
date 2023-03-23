#include <math.h>
#include "sphere.h"

Sphere::Sphere (const Vec3f& center, float radius):
    Shape()
{
    _center = center;
    _r = radius;
}

Hit Sphere::closestIntersect(const Ray& ray)
{
    Hit hit;
    hit.collisionObject = this;

    /*Calculation of intersection with sphere
    https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection.html*/

    Vec3f P = ray.pos - _center;
    float modP = P.module();

    //Elements of quadratic function
    float a = ray.dir.dot(ray.dir);
    float b = 2*ray.dir.dot(P);
    float c = modP * modP - _r*_r;

    float sqrtContents = b*b - 4*a*c;

    //Case 0: no intersection
    if (sqrtContents < 0)
        return hit;

    //Case 1: only one intersection
    if (sqrtContents == 0){
        float t = -b/(2*a);
        //Ray goes in opposite direction to the sphere
        if (t < 0)
            return hit;

        hit.wasHit = true;
        //Calculate intersection point
        hit.t = t;
        hit.pos = ray.pos + ray.dir*t;
        //Calculate normal
        hit.n = (hit.pos - _center).getNormalized();
        return hit;
    }
    
    //Case 2: two intersections
    float sqrtValue = sqrt(sqrtContents);
    float t0 = (-b + sqrtValue) / (2*a);
    float t1 = (-b - sqrtValue) / (2*a);

    //Not a valid intersection
    if (t0 < 0 || t1 < 0)
        return hit;

    hit.wasHit = true;
    hit.t = std::min(t0, t1);
    hit.pos = ray.pos + ray.dir * hit.t;
    hit.n = (hit.pos - _center).getNormalized();
    return hit;
}
