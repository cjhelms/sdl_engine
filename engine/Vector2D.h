#pragma once

struct Vector2D
{
	double x,
		y;

	//DESCRIPTION:
	//	Constructor
	Vector2D()
	{
		x = y = 0;
	}

	//DESCRIPTION:
	//	Sets position components
	//ARGUMENTS: 
	//	double x_component containing x component
	//	double y_component containing y component
	void set_vector( double x_component, double y_component )
	{
		x = x_component;
		y = y_component;
	}

	//DESCRIPTION:
	//	Sets position components
	//ARGUMENTS: 
	//	Vector2D* pointing to vector containing components
	void set_vector( Vector2D* pos )
	{
		x = pos->x;
		y = pos->y;
	}
};

