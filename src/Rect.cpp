#include "Rect.h"

Rect::Rect(const Vector2D& side1, const Vector2D& side2){
    this->set_sides(side1, side2);
}

void Rect::set_sides(const Vector2D& side1, const Vector2D& side2){
    this->side1 = side1;
    this->side2 = side2;
}

Axes get_axes(const Vector2D& head){ // TO-DO
    return Axes();
}

Vector2D project(const Vector2D& axis){ // TO-DO
    return Vector2D();
}