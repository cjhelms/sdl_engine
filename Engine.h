#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

const int SCREEN_WIDTH = 500, SCREEN_HEIGHT = 700, ERASE = 255;
const char UP_ARROW_KEY = 1, RIGHT_ARROW_KEY = 2, DOWN_ARROW_KEY = 3, 
LEFT_ARROW_KEY = 4;

class Engine
{
	private:

	SDL_Renderer * renderer;
	SDL_Window* window;
	SDL_Color color_key, color_erase;
	SDL_Event e;
	bool quit;

	public:

	//DESCRIPTION:
	//	Constructor
	Engine();

	//DESCRIPTION	
	//	Destructor
	~Engine();

	//DESCRIPTION:
	//	Initializes SDL & SDL subsystems
	void init();

	//DESCRIPTION: 
	//	Creates a window
	//ARGUMENTS: 
	//	string containing the title
	void create_window( std::string title );

	//DESCRIPTION:
	//	Creates a renderer
	//ARGUMENTS:
	//	bool v_sync where true enables v_sync; false by default
	void create_renderer( bool v_sync = false );

	//DESCRIPTION: 
	//	Loads surface from computer files
	//ARGUMENTS: 
	//	string containing file path,
	//	bool where true activates color keying
	//RETURN: 
	//	SDL_Texture*; points to the active texture
	SDL_Texture* load_media( std::string path, bool color_keying = false );

	//DESCRIPTION:
	//	Draws texture to screen
	//ARGUMENTS: 
	//	SDL_Texture* pointing to texture to be rendered
	//	SDL_Rect* pointing to a box enclosing the destination location
	//	SDL_Rect* pointing to a box enclosing the source location
	//NOTE:
	//	Leave SDL_Rect* = NULL to enclose entire location
	void render_texture( SDL_Texture* active_texture, SDL_Rect* dst_loc = NULL,
						 SDL_Rect* src_loc = NULL );

	//DESCRIPTION:
	//	Draws box outline to the screen
	//ARGUMENTS: 
	//	SDL_Rect* pointing to the rectangle to render
	//	SDL_Color* pointing to the color to render it with
	void draw_box( SDL_Rect* box, SDL_Color* color );

	//DESCRIPTION:
	//	Processes all events in the queue
	//RETURN: 
	//	vector<SDL_Event> of SDL_Events that are in the queue
	std::vector<SDL_Event> handle_events();

	//DESCRIPTION:
	//	Determines what key has been struck by user
	//ARGUMENTS:
	//	SDL_Event* pointing to event to handle
	//RETURN: 
	//	char containing active key
	char handle_key_strike(SDL_Event* c_e);

	//DESCRIPTION:
	//	Clears the screen with the erase color
	void clear_screen();

	//DESCRIPTION:
	//	Updates the screen
	void update();

	//DESCRIPTION:
	//	Sets key color
	//ARGUMENTS: 
	//	SDL_Color* pointing to color key color
	void set_key_color( SDL_Color* color );

	//DESCRIPTION:
	//	Gets quit
	bool get_quit();
};