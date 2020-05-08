#include "Engine.h"

Engine::Engine()
{
	window = NULL;
	renderer = NULL;
	quit = false;

	color_key.r = color_key.g = color_key.b = color_key.a = 0;
	color_erase.r = color_erase.g = color_erase.b = ERASE;
	color_erase.a = 255;
}

Engine::~Engine()
{
	if( window != NULL )
	{
		SDL_DestroyWindow( window );
		window = NULL;
	}

	if( renderer != NULL )
	{
		SDL_DestroyRenderer( renderer );
		renderer = NULL;
	}

	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
}

void Engine::init()
{
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		std::cout << "FAIL: Engine has failed to initialize; Error: "
			<< SDL_GetError() << std::endl;
	}

	if( IMG_Init( IMG_INIT_PNG ) < 0 )
	{
		std::cout << "FAIL: Engine has failed to initialize; Error: "
			<< IMG_GetError() << std::endl;
	}

	if( Mix_Init( MIX_INIT_MP3 ) < 0 )
	{
		std::cout << "FAIL: Engine has failed to initialize; Error: "
			<< Mix_GetError() << std::endl;
	}

	if( TTF_Init() < 0 )
	{
		std::cout << "FAIL: Engine has failed to initialize; Error: "
			<< TTF_GetError() << std::endl;
	}
}

void Engine::create_window( std::string title )
{
	window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED,
							   SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
							   SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	if( window == NULL )
	{
		std::cout << "FAIL: Engine has failed to create a window; Error: "
			<< SDL_GetError() << std::endl;
	}
}

void Engine::create_renderer( bool v_sync )
{
	if( window != NULL )
	{
		SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

		if( v_sync )
		{
			SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1" );
		}

		renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

		if( renderer == NULL )
		{
			std::cout << "FAIL: Engine has failed to create a renderer; "
				<< "Error: " << SDL_GetError() << std::endl;
		}
	}
	else
	{
		std::cout << "FAIL: Engine has failed to create a renderer; Error: "
			<< "Window has not been created" << std::endl;
	}

}

SDL_Texture* Engine::load_media( std::string path, bool color_keying )
{
	SDL_Texture* loaded_texture = NULL;
	SDL_Surface* loaded_surface = NULL;

	loaded_surface = IMG_Load( path.c_str() );

	if( loaded_surface == NULL )
	{
		std::cout << "FAIL: Engine has failed to load media; Error: "
			<< IMG_GetError() << std::endl;
	}
	else if( renderer != NULL )
	{
		if( color_keying = true )
		{
			if( SDL_SetColorKey( loaded_surface, SDL_TRUE,
								 SDL_MapRGB( loaded_surface->format, color_key.r,
											 color_key.g, color_key.b ) ) < 0 )
			{
				std::cout << "FAIL: Engine has failed to load media; Error: "
					<< SDL_GetError() << std::endl;
			}
		}

		loaded_texture = SDL_CreateTextureFromSurface( renderer,
													   loaded_surface );

		if( loaded_texture == NULL )
		{
			std::cout << "FAIL: Engine has failed to load media; Error: "
				<< SDL_GetError() << std::endl;
		}

		SDL_FreeSurface( loaded_surface );
		loaded_surface = NULL;
	}
	else
	{
		std::cout << "FAIL: Engine has failed to load media; Error: "
			<< "Renderer has not been created" << std::endl;
	}

	return loaded_texture;
}

void Engine::render_texture( SDL_Texture* active_texture, SDL_Rect* dst_loc,
							 SDL_Rect* src_loc )
{
	if( window == NULL )
	{
		std::cout << "FAIL: Engine has failed to render texture; Error: "
			<< "Window has not been created" << std::endl;
	}
	else if( renderer == NULL )
	{
		std::cout << "FAIL: Engine has failed to render texture; Error: "
			<< "Renderer has not been created" << std::endl;
	}
	else
	{
		if( SDL_RenderCopy( renderer, active_texture, dst_loc, src_loc ) < 0 )
		{
			std::cout << "FAIL: Engine has failed to render texture: Error: "
				<< SDL_GetError() << std::endl;
		}
	}
}

void Engine::draw_box( SDL_Rect* box, SDL_Color* color )
{
	SDL_SetRenderDrawColor( renderer, color->r, color->g, color->b, color->a );
	SDL_RenderDrawRect( renderer, box );
}

std::vector<SDL_Event> Engine::handle_events()
{
	static std::vector<SDL_Event> current_events;

	current_events.clear();

	while( SDL_PollEvent( &e ) )
	{
		if( e.type == SDL_QUIT || (e.type == SDL_KEYDOWN
								   && e.key.keysym.sym == SDLK_ESCAPE) )
		{
			quit = true;
		}
		else
		{
			current_events.push_back( e );
		}
	}

	return current_events;
}

char Engine::handle_key_strike( SDL_Event* c_e )
{
	char active_key = '\0';

	if( c_e->key.keysym.sym == SDLK_0 || c_e->key.keysym.sym == SDLK_KP_0 )
	{
		active_key = '0';
	}

	if( c_e->key.keysym.sym == SDLK_1 || c_e->key.keysym.sym == SDLK_KP_1 )
	{
		active_key = '1';
	}

	if( c_e->key.keysym.sym == SDLK_2 || c_e->key.keysym.sym == SDLK_KP_2 )
	{
		active_key = '2';
	}

	if( c_e->key.keysym.sym == SDLK_3 || c_e->key.keysym.sym == SDLK_KP_3 )
	{
		active_key = '3';
	}

	if( c_e->key.keysym.sym == SDLK_4 || c_e->key.keysym.sym == SDLK_KP_4 )
	{
		active_key = '4';
	}

	if( c_e->key.keysym.sym == SDLK_5 || c_e->key.keysym.sym == SDLK_KP_5 )
	{
		active_key = '5';
	}

	if( c_e->key.keysym.sym == SDLK_6 || c_e->key.keysym.sym == SDLK_KP_6 )
	{
		active_key = '6';
	}

	if( c_e->key.keysym.sym == SDLK_7 || c_e->key.keysym.sym == SDLK_KP_7 )
	{
		active_key = '7';
	}

	if( c_e->key.keysym.sym == SDLK_8 || c_e->key.keysym.sym == SDLK_KP_8 )
	{
		active_key = '8';
	}

	if( c_e->key.keysym.sym == SDLK_9 || c_e->key.keysym.sym == SDLK_KP_9 )
	{
		active_key = '9';
	}

	if( c_e->key.keysym.sym == SDLK_RETURN 
		|| c_e->key.keysym.sym == SDLK_KP_ENTER )
	{
		active_key = '\r';
	}

	if( c_e->key.keysym.sym == SDLK_MINUS 
		|| c_e->key.keysym.sym == SDLK_KP_MINUS )
	{
		active_key = '-';
	}

	if( c_e->key.keysym.sym == SDLK_a )
	{
		active_key = 'A';
	}

	if( c_e->key.keysym.sym == SDLK_b )
	{
		active_key = 'B';
	}

	if( c_e->key.keysym.sym == SDLK_c )
	{
		active_key = 'C';
	}

	if( c_e->key.keysym.sym == SDLK_d )
	{
		active_key = 'D';
	}

	if( c_e->key.keysym.sym == SDLK_e )
	{
		active_key = 'E';
	}

	if( c_e->key.keysym.sym == SDLK_f )
	{
		active_key = 'F';
	}

	if( c_e->key.keysym.sym == SDLK_g )
	{
		active_key = 'G';
	}

	if( c_e->key.keysym.sym == SDLK_h )
	{
		active_key = 'H';
	}

	if( c_e->key.keysym.sym == SDLK_i )
	{
		active_key = 'I';
	}

	if( c_e->key.keysym.sym == SDLK_j )
	{
		active_key = 'J';
	}

	if( c_e->key.keysym.sym == SDLK_k )
	{
		active_key = 'K';
	}

	if( c_e->key.keysym.sym == SDLK_l )
	{
		active_key = 'L';
	}

	if( c_e->key.keysym.sym == SDLK_m )
	{
		active_key = 'M';
	}

	if( c_e->key.keysym.sym == SDLK_n )
	{
		active_key = 'N';
	}

	if( c_e->key.keysym.sym == SDLK_o )
	{
		active_key = 'O';
	}

	if( c_e->key.keysym.sym == SDLK_p )
	{
		active_key = 'P';
	}

	if( c_e->key.keysym.sym == SDLK_q )
	{
		active_key = 'Q';
	}

	if( c_e->key.keysym.sym == SDLK_r )
	{
		active_key = 'R';
	}

	if( c_e->key.keysym.sym == SDLK_s )
	{
		active_key = 'S';
	}

	if( c_e->key.keysym.sym == SDLK_t )
	{
		active_key = 'T';
	}

	if( c_e->key.keysym.sym == SDLK_u )
	{
		active_key = 'U';
	}

	if( c_e->key.keysym.sym == SDLK_v )
	{
		active_key = 'V';
	}

	if( c_e->key.keysym.sym == SDLK_w )
	{
		active_key = 'W';
	}

	if( c_e->key.keysym.sym == SDLK_x )
	{
		active_key = 'X';
	}

	if( c_e->key.keysym.sym == SDLK_y )
	{
		active_key = 'Y';
	}

	if( c_e->key.keysym.sym == SDLK_z )
	{
		active_key = 'Z';
	}

	if( c_e->key.keysym.sym == SDLK_TAB )
	{
		active_key = '\t';
	}

	if( c_e->key.keysym.sym == SDLK_BACKSPACE )
	{
		active_key = '\b';
	}

	if( c_e->key.keysym.sym == SDLK_UP )
	{
		active_key = UP_ARROW_KEY;
	}

	if( c_e->key.keysym.sym == SDLK_RIGHT )
	{
		active_key = RIGHT_ARROW_KEY;
	}

	if( c_e->key.keysym.sym == SDLK_DOWN )
	{
		active_key = DOWN_ARROW_KEY;
	}

	if( c_e->key.keysym.sym == SDLK_LEFT )
	{
		active_key = LEFT_ARROW_KEY;
	}

	return active_key;
}

void Engine::clear_screen()
{
	if( window == NULL )
	{
		std::cout << "FAIL: Engine has failed to clear screen; Error: "
			<< "Window has not been created" << std::endl;
	}
	else if( renderer == NULL )
	{
		std::cout << "FAIL: Engine has failed to clear screen; Error: "
			<< "Renderer has not been created" << std::endl;
	}
	else
	{
		if( SDL_SetRenderDrawColor( renderer, color_erase.r, color_erase.g,
									color_erase.b, color_erase.a ) < 0 )
		{
			std::cout << "FAIL: Engine has failed to clear screen; Error: "
				<< SDL_GetError() << std::endl;
		}
		else if( SDL_RenderClear( renderer ) < 0 )
		{
			std::cout << "FAIL: Engine has failed to clear screen; Error: "
				<< SDL_GetError() << std::endl;
		}
	}
}

void Engine::update()
{
	if( window == NULL )
	{
		std::cout << "FAIL: Engine has failed to update; Error: "
			<< "Window has not been created" << std::endl;
	}
	else if( renderer == NULL )
	{
		std::cout << "FAIL: Engine has failed to update; Error: "
			<< "Renderer has not been created" << std::endl;
	}
	else
	{
		SDL_RenderPresent( renderer );
	}
}

void Engine::set_key_color( SDL_Color* color )
{
	color_key = *color;
}

bool Engine::get_quit()
{
	return quit;
}