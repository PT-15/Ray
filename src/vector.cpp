#include "vector.h"
#include <math.h>

Vec3f::Vec3f()
{
    _x = 0.;
    _y = 0.;
    _z = 0.;
}

Vec3f::Vec3f(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

Vec3f::Vec3f(const Vec3f& vec)
{
    _x = vec._x;
    _y = vec._y;
    _z = vec._z;
}

float& Vec3f::x ()
{
    return _x;
}
float& Vec3f::y ()
{
    return _y;
}
float& Vec3f::z ()
{
    return _z;
}

float Vec3f::x () const
{
    return _x;
}
float Vec3f::y () const
{
    return _y;
}
float Vec3f::z () const
{
    return _z;
}

Vec3f Vec3f::operator+ (const Vec3f& v) const
{
    return Vec3f((v.x() + _x), (v.y() + _y), (v.z() + _z));
}

Vec3f Vec3f::operator- (const Vec3f& v) const
{
    return Vec3f((_x - v._x), (_y - v._y), (_z - v._z));
}

Vec3f Vec3f::operator* (float t) const
{
    return Vec3f (_x*t, _y*t, _z*t);
}

float Vec3f::dot(const Vec3f& v) const
{
    return _x*v._x + _y*v._y + _z*v._z;
}



float Vec3f::module () const
{
    return sqrt(_x*_x + _y*_y + _z*_z);
}

void Vec3f::normalize()
{
    float mod = module();
    if (mod == 0.){
        printf("You're doing it wrong, dummy!\n");
        return;
    }
    _x = _x/mod;
    _y = _y/mod;
    _z = _z/mod;
}

Vec3f Vec3f::getNormalized() const
{
    float mod = module();
    if (mod == 0.){
        printf("You're doing it wrong, dummy!\n");
        return Vec3f(0,0,0);
    }

    return Vec3f(_x/mod, _y/mod, _z/mod);
}
