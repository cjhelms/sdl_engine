#pragma once

#include "Point.h"
#include <iostream>

// TO-DO: vector shouldn't have a point

const double VERT_CUTOFF = 0.05; // |y| >= 20*|x| ==> vertical

struct Vector2D
{
	Point p;
	double xv, yv;

	Vector2D();
	Vector2D( double xv, double yv );
	Vector2D( const Point& p, double xv, double yv );
	Vector2D( const Vector2D& v );
	void set_vector( double xv, double yv );
	void set_vector( const Point& p, double xv, double yv );
	void set_vector( const Vector2D &v );
	void operator=( const Vector2D &v );
	friend std::ostream &operator<<( std::ostream &output, const Vector2D &v );
	friend Vector2D make_vert_vector(int x);
	friend Vector2D make_horiz_vector(int y);
	friend Vector2D p2p_vector( const Point& p1, const Point& p2 );

	void normalize();
	double dot_prod( const Vector2D& v ) const;
	void reflect( const Vector2D& v );
	bool is_vertical() const;
	bool is_horizontal() const;
};

std::ostream &operator<<( std::ostream &output, const Vector2D &v );
Vector2D make_vert_vector(int x);
Vector2D make_horiz_vector(int y);
Vector2D p2p_vector( const Point& p1, const Point& p2 );