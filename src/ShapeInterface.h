#pragma once

#include <vector>
#include "Vector2D.h"

typedef std::vector<Vector2D> Axes;

struct ShapeInterface
{

    virtual void update(const Point& p, const Vector2D h) = 0;
    virtual Axes get_axes() = 0;
    virtual Vector2D project(Vector2D axis) = 0;

};
