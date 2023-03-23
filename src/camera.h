#pragma once

#include <iostream>
#include "vector.h"
#include "frameBuffer.h"
#include "ray.h"

class Camera
{
    public:
        Camera(Vec3f position, float hFieldOfView_rad);
        Ray primaryRay(int x, int y, const FrameBuffer& fb);

    private:
        Vec3f _position;
        float _hfov; //horizontal field of view in rad
};
