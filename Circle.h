#pragma once

struct Circle
{
	int radius;
	Vector2D pos;

	//DESCRIPTION:
	//	Constructor
	Circle()
	{
		radius = 0;
	}

	//DESCRIPTION:
	//	Sets circle
	//ARGUMENTS: 
	//	double x_pos containing x position
	//	double y_pos containing y position
	//	int r containing radius
	void set_vector( double x_pos, double y_pos, int r )
	{
		pos.x = x_pos;
		pos.y = y_pos;
		radius = r;
	}

	//DESCRIPTION:
	//	Sets circle
	//ARGUMENTS: 
	//	Circle* pointing to circle containing position & radius
	void set_vector( Circle* c )
	{
		pos.x = c->pos.x;
		pos.y = c->pos.y;
		radius = c->radius;
	}
};