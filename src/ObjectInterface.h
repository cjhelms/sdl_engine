#pragma once

#include "ShapeInterface.h"

class ObjectInterface {
private:

    Point pos;
    Vector2D vel, accel, head;
    ShapeInterface* hb;

    Vector2D project_hb(Vector2D axis) const;

public:

    ObjectInterface();
    ObjectInterface(ShapeInterface* shape);
    virtual ~ObjectInterface() = 0;
    void set_hb_shape(ShapeInterface* shape);
    bool intersect(const ObjectInterface& obj) const;
    Axes get_hb_axes() const;
    Vector2D get_vel() const;
    Vector2D get_accel() const;
    Vector2D get_head() const;
    void set_vel(const Vector2D& vel);
    void set_accel(const Vector2D& accel);
    void set_head(const Vector2D& head);

    virtual void update() = 0;

};