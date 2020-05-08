#pragma once

#include <SDL.h>
#include <iostream>
#include <cmath>
#include "Circle.h"
#include "Vector2D.h"

//DESCRIPTION:
//	Calculates the distance between two points
//ARGUMENTS:
//	Vector2D* p1 pointing to point one
//	Vector2D* p2 pointing to point two
//RETURN:
//	double containing distance
double distance( Vector2D* p1, Vector2D* p2 )
{
	return sqrt( pow( p1->x - p2->x, 2.0 ) + pow( p1->y - p2->y, 2.0 ) );
}

//DESCRIPTION:
//	Calculates point-to-point vector of two points
//ARGUMENTS:
//	Vector2D* p_init pointing to initial position
//	Vector2D* p_fin pointing to final position
//RETURN:
//	Vector2D containing point-to-point vector
Vector2D p2p_vector( Vector2D* p_init, Vector2D* p_fin )
{
	Vector2D p2p;

	p2p.set_vector( p_fin->x - p_init->x, p_fin->y - p_init->y );

	return p2p;
}

//DESCRIPTION:
//	Normalizes a vector
//ARGUMENTS:
//	Vector2D* v pointing to vector to normalize
void normalize( Vector2D* v )
{
	double mag = sqrt( v->x * v->x + v->y * v->y );

	v->set_vector( v->x / mag, v->y / mag );
}

//DESCRIPTION:
//	Tests collision between a circle & a box
//ARGUMENTS:
//	Vector2D* containing unit vector of collision
//	Circle* c_hb pointing to hitbox of circle
//	SDL_Rect* box_hb pointing to hitbox of box
//RETURN:
//	bool where true indicates collision
bool test_collision( Vector2D* n, Circle* c_hb, SDL_Rect* box_hb )
{
	bool is_collided = false;
	Vector2D c_p;

	//Closest point in the x-direction
	if( c_hb->pos.x < box_hb->x )
	{
		c_p.x = box_hb->x;
	}
	else if( c_hb->pos.x > box_hb->x + box_hb->w )
	{
		c_p.x = box_hb->x + box_hb->w;
	}
	else
	{
		c_p.x = c_hb->pos.x;
	}

	//Closest point in the y-direction
	if( c_hb->pos.y < box_hb->y )
	{
		c_p.y = box_hb->y;
	}
	else if( c_hb->pos.y > box_hb->y + box_hb->h )
	{
		c_p.y = box_hb->y + box_hb->h;
	}
	else
	{
		c_p.y = c_hb->pos.y;
	}

	//Check
	if( distance( &c_p, &c_hb->pos ) <= (double)c_hb->radius )
	{
		Vector2D vector = p2p_vector( &c_p, &c_hb->pos );
		n->set_vector( &vector );
		normalize( n );

		is_collided = true;
	}

	return is_collided;
}

//DESCRIPTION:
//	Resolves collision of a ball with an object
//ARGUMENTS:
//	Vector2D* pointing to normal vector of collision
//	Ball* c pointing to the ball
void resolve_collision( Ball* c )
{
	Vector2D vel_r_u, rev_pos;

	vel_r_u.set_vector( c->get_velocity()->x * -1, c->get_velocity()->y * -1 );
	//std::cout << vel_r_u.x << " " << vel_r_u.y << std::endl;

	normalize( &vel_r_u );
	//std::cout << vel_r_u.x << " " << vel_r_u.y << std::endl;

	rev_pos.set_vector( c->get_position()->x + vel_r_u.x, 
						c->get_position()->y + vel_r_u.y );

	c->set_position( &rev_pos );

	c->get_collider()->pos.set_vector( c->get_position() );
}

//DESCRIPTION:
//	Calculates dot product of vector v1 & vector v2
//ARGUMENTS:
//	Vector2D* v1 pointing to vector one
//	Vector2D* v2 pointing to vectore two
//RETURN:
//	double containing dot product result
double dot_prod( Vector2D* v1, Vector2D* v2 )
{
	return v1->x * v2->x + v1->y * v2->y;
}

//DESCRIPTION:
//	Reflects vector v1 over vector v2
//ARGUMENTS:
//	Vector2D* v1 pointing to vector one
//	Vector2D* v2 pointing to vectore two
void reflect( Vector2D* v1, Vector2D* v2 )
{
	v1->set_vector( v1->x - 2 * dot_prod( v1, v2 ) * v2->x,
					v1->y - 2 * dot_prod( v1, v2 ) * v2->y );
}