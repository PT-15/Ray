#include "camera.h"
#include <math.h>

Camera::Camera (Vec3f position, float hFieldOfView_rad)
{
    _position = position;
    _hfov = hFieldOfView_rad;
}

Ray Camera::primaryRay(int x, int y, const FrameBuffer& fb)
{
    Ray r;

    float width = (float)fb.getWidth();
    float height = (float)fb.getHeight();

    //Convert frame buffer coord to space coord
    y = height - y - height/2.;
    x = x - width/2.;

    //Get direction vector
    float spaceX = tan(_hfov/2.);
    r.dir.x() = (x * spaceX) / (width/2.);

    float vfov = _hfov / fb.getAspectRatio();
    float spaceY = tan(vfov/2.);
    r.dir.y() = (y * spaceY) / (height/2.);

    r.dir.z() = -1.;

    r.dir.normalize();

    //Position vector for now is 0
    r.pos = {0., 0., 0.};

    return r;
}
