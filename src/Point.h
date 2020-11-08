#pragma once

#include <iostream>
#include <math.h>

// TO-DO: move point reflection to here

struct Point{
    int xp, yp;

    Point();
    Point(int xp, int yp);
    Point(const Point& p);
    void set_point(int xp, int yp);
    void set_point(const Point& p);
    void operator=( const Point& p );
    friend std::ostream& operator<<( std::ostream& output, const Point& p );
    
    double distance( const Point& p ) const;
};

std::ostream& operator<<( std::ostream& output, const Point& p );