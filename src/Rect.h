#pragma once

#include "ShapeInterface.h"

struct Rect : public ShapeInterface
{

    Vector2D side1, side2;

    Rect(const Vector2D& side1, const Vector2D& side2);
    void set_sides(const Vector2D& side1, const Vector2D& side2);
    Axes get_axes(const Vector2D& dir); // TO-DO
    Vector2D project(const Vector2D& axis); // TO-DO

};