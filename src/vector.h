#pragma once

#include <iostream>

class Vec3f
{
    public:
        Vec3f();
        Vec3f(float x, float y, float z);
        Vec3f(const Vec3f& vec);
        float& x();
        float& y();
        float& z();
        float x() const;
        float y() const;
        float z() const;

        Vec3f operator+ (const Vec3f& v) const;
        Vec3f operator-(const Vec3f& v) const;
        Vec3f operator* (float t) const;
        float dot(const Vec3f& v) const; //escalar
        Vec3f crossProduct(const Vec3f& v) const; //vectorial

        float module() const;
        void normalize();
        Vec3f getNormalized() const;

    private:
        float _x;
        float _y;
        float _z;
};