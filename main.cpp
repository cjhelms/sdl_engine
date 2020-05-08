#include <iostream>
#include <SDL.h>
#include <vector>
#include <cmath>
#include "Engine.h"
#include "Ball.h"
#include "Collision.h"

int main( int argc, char* args[] )
{
	Ball ball;
	Engine my_engine;
	SDL_Color color_key = { 0, 255, 255, 255 }, wall_color = { 0, 0, 0, 255 };
	Vector2D n_u;
	std::vector<SDL_Rect> wall;

	//Initialize engine & graphics display
	my_engine.init();
	my_engine.create_window( "Physics Experiment" );
	my_engine.create_renderer(true);

	//Set color key value
	my_engine.set_key_color( &color_key );

	//Initialize ball
	ball.init( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10 );
	ball.load_sprite( my_engine.load_media( "ball_sprite.png", true ) );

	//Create wall
	SDL_Rect L_wall = { 0, 0, 10, SCREEN_HEIGHT }, T_wall = { 0, 0, SCREEN_WIDTH, 10 },
		R_wall = { SCREEN_WIDTH - 10, 0, 10, SCREEN_HEIGHT }, 
		B_wall = { 0, SCREEN_HEIGHT - 10, SCREEN_WIDTH, 10 };

	wall.push_back( L_wall );
	wall.push_back( T_wall );
	wall.push_back( R_wall );
	wall.push_back( B_wall );

	//Main loop
	while( !my_engine.get_quit() )
	{
		//Clear screen
		my_engine.clear_screen();

		//Draws wall to screen
		for( unsigned i = 0; i < wall.size(); i++ )
		{
			my_engine.draw_box( &wall.at(i), &wall_color );
		}

		//Render ball to screen
		ball.render_sprite( &my_engine );

		//Update balls coordinates
		ball.update_position();

		//Check for collisions
		for( unsigned i = 0; i < wall.size(); i++ )
		{
			if( test_collision( &n_u, ball.get_collider(), &wall.at(i) ) )
			{
				while( test_collision( &n_u, ball.get_collider(), &wall.at(i) ) )
				{
					resolve_collision( &ball );
				}

				reflect( ball.get_velocity(), &n_u );
			}
		}

		//Handle ball event
		ball.handle_event( &my_engine );

		//Update screen
		my_engine.update();
	}
	
	return 0;
}