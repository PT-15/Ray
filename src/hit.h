#pragma once

#include <iostream>
#include "vector.h"

class Shape;

struct Hit {
    Vec3f pos;
    Vec3f n; //normal
    float t; //Ray distance
    bool wasHit = false;
    Shape* collisionObject;
};
