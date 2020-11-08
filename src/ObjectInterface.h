#pragma once

#include "ShapeInterface.h"

class ObjectInterface {
private:

    Point pos;
    Vector2D vel, accel, head;
    ShapeInterface* hb;

public:

    virtual void update() = 0;
    virtual Vector2D is_collided(ObjectInterface * obj) = 0; // check ray against hitbox, return reflection vector
    virtual void handle_collision(Vector2D ref); // use reflection vector to handle collision
};