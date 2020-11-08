#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <unordered_set>
#include "src/Vector2D.h"
#include "src/ShapeInterface.h"
#include "src/ObjectInterface.h"

/*
 * TO-DO:
 *   - implement an efficient way to check collisions against every object
 *   - draw every object to screen on update
 *   - investigate multi-threading (check collisions on seperate thread)
 */

const int SCREEN_WIDTH = 500, SCREEN_HEIGHT = 700, ERASE = 255;
const char UP_ARROW_KEY = 1, RIGHT_ARROW_KEY = 2, DOWN_ARROW_KEY = 3, 
LEFT_ARROW_KEY = 4;

using namespace std;

class Engine
{
private:

	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Color color_key, color_erase;
	SDL_Event e;
	bool quit;
	unordered_set<ObjectInterface*> objects;

public:

	Engine();
	~Engine();

	void init();
	void create_window( std::string title );
	void create_renderer( bool v_sync = false );
	SDL_Texture* load_media( std::string path, bool color_keying = false );
	void render_texture( SDL_Texture* active_texture, SDL_Rect* dst_loc = NULL,
		SDL_Rect* src_loc = NULL );
	void draw_box( SDL_Rect* box, SDL_Color* color );
	vector<SDL_Event> handle_events();
	char handle_key_strike(SDL_Event* c_e);
	void clear_screen();
	void update(); // TO-DO
	void set_key_color( SDL_Color* color );
	bool get_quit();
	void handle_collisions(); // TO-DO
	void register_object(ObjectInterface* obj);
	void deregister_object(ObjectInterface* obj);
};