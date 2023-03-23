#include "shape.h"

Shape::Shape()
{
    _material = NULL;
}

Shape::Shape(Material* material)
{
    _material = material;
}

Material* Shape::getMaterial() const
{
    return _material;
}

void Shape::setMaterial(Material* newMaterial)
{
    _material = newMaterial;
}
