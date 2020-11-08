#pragma once

#include "Vector2D.h"

class ShapeInterface
{
private:

public:

    virtual Vector2D find_intersection(Vector2D ray) = 0; // check if ray intersects hb

};
