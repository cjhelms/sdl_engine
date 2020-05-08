#pragma once

#include <string>
#include <cmath>
#include <vector>
#include "Engine.h"
#include "Vector2D.h"
#include "Circle.h"

const double ACCELERATION = 0.01;

class Ball
{
	private:

	Vector2D position, velocity;
	Circle collider;
	SDL_Texture* sprite;
	double buffer_x, buffer_y, change_vel_x, change_vel_y;
	int radius, time;

	public:

	//DESCRIPTION:
	//	Constructor
	Ball();

	//DESCRIPTION:
	//	Destructor
	~Ball();

	//DESCRIPTION:
	//	Initializes ball
	//ARGUMENTS: 
	//	double containing initial x position, default 0
	//	double containing initial y position, default 0
	//	int containing initial radius, default 0
	//	double containing initial x velocity, default 0
	//	double containing initial y velocity, default 0
	void init( double x = 0, double y = 0, int r = 0, double x_vel = 0, double y_vel = 0 );

	//DESCRIPTION:
	//	Loads ball sprite
	//ARGUMENTS: 
	//	SDL_Texture* pointing to sprite texture
	void load_sprite( SDL_Texture* s );

	//DESCRIPTION:
	//	Renders ball sprite
	//ARGUMENTS: 
	//	Engine* g pointing to the engine to render with
	void render_sprite( Engine* g );

	//DESCRIPTION:
	//	Updates position based on velocity
	void update_position();

	//DESCRIPTION:
	//	Handles events from user
	//ARGUMENTS: 
	//	Engine* pointing to engine used for events
	void handle_event( Engine* g );

	//DESCRIPTION:
	//	Sets position of ball
	//ARGUMENTS: 
	//	Vector2D* pointing to a Vector2D containing position
	void set_position( Vector2D* pos );

	//DESCRIPTION:
	//	Sets velocity of ball
	//ARGUMENTS: 
	//	Vector2D* pointing to a Vector2D containing velocity
	void set_velocity( Vector2D* vel );

	//DESCRIPTION:
	//	Gets pointer to position of ball
	//RETURN:
	//	Vector2D* pointing to position
	Vector2D* get_position();

	//DESCRIPTION:
	//	Gets pointer to velocity
	//RETURN:
	//	Vector2D* pointing to velocity
	Vector2D* get_velocity();

	//DESCRIPTION:
	//	Gets pointer to collider
	//RETURN:
	//	Circle* pointing to collider
	Circle* get_collider();
};