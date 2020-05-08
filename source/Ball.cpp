#include "Ball.h"

Ball::Ball()
{
	sprite = NULL;
	time = radius = 0;
	buffer_x = buffer_y = change_vel_x = change_vel_y = 0;
}

Ball::~Ball()
{
	if( sprite != NULL )
	{
		SDL_DestroyTexture( sprite );
		sprite = NULL;
	}
}

void Ball::init( double x, double y, int r, double x_vel, double y_vel )
{
	position.x = collider.pos.x = x;
	position.y = collider.pos.y = y;
	radius = collider.radius = r;
	velocity.x = x_vel;
	velocity.y = y_vel;
}

void Ball::load_sprite( SDL_Texture* s )
{
	sprite = s;
}

void Ball::render_sprite( Engine* g )
{
	SDL_Rect box_pos = { (int)position.x - radius, (int)position.y - radius,
						 radius * 2, radius * 2 };

	g->render_texture( sprite, NULL, &box_pos );
}

void Ball::update_position()
{
	if( time == 0 || (velocity.x == 0 && velocity.y == 0) )
	{
		time = SDL_GetTicks();
	}
	else
	{
		buffer_x += velocity.x * (SDL_GetTicks() - time);
		buffer_y += velocity.y * (SDL_GetTicks() - time);

		time = SDL_GetTicks();
	}

	if( abs( buffer_x ) >= 1 )
	{
		position.x += buffer_x;
		collider.pos.x = position.x;

		buffer_x -= buffer_x;
	}

	if( abs( buffer_y ) >= 1 )
	{
		position.y += buffer_y;
		collider.pos.y = position.y;

		buffer_y -= buffer_y;
	}
}

void Ball::handle_event( Engine* g )
{
	std::vector<SDL_Event> e = g->handle_events();

	for(unsigned i = 0; i < e.size(); i++)
	{
		if( e.at(i).type == SDL_KEYDOWN && e.at(i).key.repeat == 0 )
		{
			switch( g->handle_key_strike( &e.at(i) ) )
			{
				case UP_ARROW_KEY: change_vel_y = -ACCELERATION;
					break;
				case RIGHT_ARROW_KEY: change_vel_x = ACCELERATION;
					break;
				case DOWN_ARROW_KEY: change_vel_y = ACCELERATION;
					break;
				case LEFT_ARROW_KEY: change_vel_x = -ACCELERATION;
					break;
				case '\r': velocity.x = velocity.y = 0;
					break;
			}
		}
		else if( e.at( i ).type == SDL_KEYUP && e.at( i ).key.repeat == 0 )
		{
			switch( g->handle_key_strike( &e.at( i ) ) )
			{
				case UP_ARROW_KEY: change_vel_y = 0;
					break;
				case RIGHT_ARROW_KEY: change_vel_x = 0;
					break;
				case DOWN_ARROW_KEY: change_vel_y = 0;
					break;
				case LEFT_ARROW_KEY: change_vel_x = 0;
					break;
			}
		}
	}

	velocity.x += change_vel_x;
	velocity.y += change_vel_y;
}

void Ball::set_position( Vector2D* pos )
{
	position.set_vector( pos );
}

void Ball::set_velocity( Vector2D* vel )
{
	velocity.set_vector( vel );
}

Vector2D* Ball::get_position()
{
	return &position;
}

Vector2D* Ball::get_velocity()
{
	return &velocity;
}

Circle* Ball::get_collider()
{
	return &collider;
}