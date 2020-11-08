#include <iostream>
#include <SDL.h>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include "../Engine.h"

using namespace std;

void test_Engine_handle_key_strike(Engine* engine);
void test_Point_init();
void test_Point_distance();
void test_Vector2D_init();
void test_Vector2D_p2p_vector();
void test_Vector2D_normalize();
void test_Vector2D_dot_prod();
void test_Vector2D_reflect();

int main( int argc, char* args[] )
{
	Engine engine;

	engine.init();
	engine.create_window("Testing");
	engine.create_renderer();

	test_Engine_handle_key_strike(&engine);
	test_Point_init();
	test_Point_distance();
	test_Vector2D_init();
	test_Vector2D_p2p_vector();
	test_Vector2D_normalize();
	test_Vector2D_dot_prod();
	test_Vector2D_reflect();
	
	return 0;
}

void test_Engine_handle_key_strike(Engine* engine){
	SDL_Event* e;
	vector<SDL_KeyCode> keycodes;

	e->key.keysym.sym = SDLK_0;
	assert(engine->handle_key_strike(e) == '0');
	e->key.keysym.sym = SDLK_1;
	assert(engine->handle_key_strike(e) == '1');
	e->key.keysym.sym = SDLK_2;
	assert(engine->handle_key_strike(e) == '2');
	e->key.keysym.sym = SDLK_3;
	assert(engine->handle_key_strike(e) == '3');
	e->key.keysym.sym = SDLK_4;
	assert(engine->handle_key_strike(e) == '4');
	e->key.keysym.sym = SDLK_5;
	assert(engine->handle_key_strike(e) == '5');
	e->key.keysym.sym = SDLK_6;
	assert(engine->handle_key_strike(e) == '6');
	e->key.keysym.sym = SDLK_7;
	assert(engine->handle_key_strike(e) == '7');
	e->key.keysym.sym = SDLK_8;
	assert(engine->handle_key_strike(e) == '8');
	e->key.keysym.sym = SDLK_9;
	assert(engine->handle_key_strike(e) == '9');
	e->key.keysym.sym = SDLK_KP_0;
	assert(engine->handle_key_strike(e) == '0');
	e->key.keysym.sym = SDLK_KP_1;
	assert(engine->handle_key_strike(e) == '1');
	e->key.keysym.sym = SDLK_KP_2;
	assert(engine->handle_key_strike(e) == '2');
	e->key.keysym.sym = SDLK_KP_3;
	assert(engine->handle_key_strike(e) == '3');
	e->key.keysym.sym = SDLK_KP_4;
	assert(engine->handle_key_strike(e) == '4');
	e->key.keysym.sym = SDLK_KP_5;
	assert(engine->handle_key_strike(e) == '5');
	e->key.keysym.sym = SDLK_KP_6;
	assert(engine->handle_key_strike(e) == '6');
	e->key.keysym.sym = SDLK_KP_7;
	assert(engine->handle_key_strike(e) == '7');
	e->key.keysym.sym = SDLK_KP_8;
	assert(engine->handle_key_strike(e) == '8');
	e->key.keysym.sym = SDLK_KP_9;
	assert(engine->handle_key_strike(e) == '9');
	e->key.keysym.sym = SDLK_RETURN;
	assert(engine->handle_key_strike(e) == '\r');
	e->key.keysym.sym = SDLK_KP_ENTER;
	assert(engine->handle_key_strike(e) == '\r');
	e->key.keysym.sym = SDLK_MINUS;
	assert(engine->handle_key_strike(e) == '-');
	e->key.keysym.sym = SDLK_KP_MINUS;
	assert(engine->handle_key_strike(e) == '-');
	e->key.keysym.sym = SDLK_a;
	assert(engine->handle_key_strike(e) == 'A');
	e->key.keysym.sym = SDLK_b;
	assert(engine->handle_key_strike(e) == 'B');
	e->key.keysym.sym = SDLK_c;
	assert(engine->handle_key_strike(e) == 'C');
	e->key.keysym.sym = SDLK_d;
	assert(engine->handle_key_strike(e) == 'D');
	e->key.keysym.sym = SDLK_e;
	assert(engine->handle_key_strike(e) == 'E');
	e->key.keysym.sym = SDLK_f;
	assert(engine->handle_key_strike(e) == 'F');
	e->key.keysym.sym = SDLK_g;
	assert(engine->handle_key_strike(e) == 'G');
	e->key.keysym.sym = SDLK_h;
	assert(engine->handle_key_strike(e) == 'H');
	e->key.keysym.sym = SDLK_i;
	assert(engine->handle_key_strike(e) == 'I');
	e->key.keysym.sym = SDLK_j;
	assert(engine->handle_key_strike(e) == 'J');
	e->key.keysym.sym = SDLK_k;
	assert(engine->handle_key_strike(e) == 'K');
	e->key.keysym.sym = SDLK_l;
	assert(engine->handle_key_strike(e) == 'L');
	e->key.keysym.sym = SDLK_m;
	assert(engine->handle_key_strike(e) == 'M');
	e->key.keysym.sym = SDLK_n;
	assert(engine->handle_key_strike(e) == 'N');
	e->key.keysym.sym = SDLK_o;
	assert(engine->handle_key_strike(e) == 'O');
	e->key.keysym.sym = SDLK_p;
	assert(engine->handle_key_strike(e) == 'P');
	e->key.keysym.sym = SDLK_q;
	assert(engine->handle_key_strike(e) == 'Q');
	e->key.keysym.sym = SDLK_r;
	assert(engine->handle_key_strike(e) == 'R');
	e->key.keysym.sym = SDLK_s;
	assert(engine->handle_key_strike(e) == 'S');
	e->key.keysym.sym = SDLK_t;
	assert(engine->handle_key_strike(e) == 'T');
	e->key.keysym.sym = SDLK_u;
	assert(engine->handle_key_strike(e) == 'U');
	e->key.keysym.sym = SDLK_v;
	assert(engine->handle_key_strike(e) == 'V');
	e->key.keysym.sym = SDLK_w;
	assert(engine->handle_key_strike(e) == 'W');
	e->key.keysym.sym = SDLK_x;
	assert(engine->handle_key_strike(e) == 'X');
	e->key.keysym.sym = SDLK_y;
	assert(engine->handle_key_strike(e) == 'Y');
	e->key.keysym.sym = SDLK_z;
	assert(engine->handle_key_strike(e) == 'Z');
	e->key.keysym.sym = SDLK_TAB;
	assert(engine->handle_key_strike(e) == '\t');
	e->key.keysym.sym = SDLK_BACKSPACE;
	assert(engine->handle_key_strike(e) == '\b');
	e->key.keysym.sym = SDLK_UP;
	assert(engine->handle_key_strike(e) == UP_ARROW_KEY);
	e->key.keysym.sym = SDLK_RIGHT;
	assert(engine->handle_key_strike(e) == RIGHT_ARROW_KEY);
	e->key.keysym.sym = SDLK_DOWN;
	assert(engine->handle_key_strike(e) == DOWN_ARROW_KEY);
	e->key.keysym.sym = SDLK_LEFT;
	assert(engine->handle_key_strike(e) == LEFT_ARROW_KEY);
	cout << "test_handle_key_strike passed!" << endl;
}

void test_Point_init(){
	Point p;
	assert(p.xp == 0 && p.yp == 0);
	p.set_point(1,2);
	assert(p.xp == 1 && p.yp == 2);
	Point k(p);
	assert(k.xp == 1 && k.yp == 2);
	Point u = k;
	assert(u.xp == 1 && u.yp == 2);
	Point r;
	r = k;
	assert(r.xp == 1 && r.yp == 2);
	Point o(3,4);
	assert(o.xp == 3 && o.yp == 4);
	r = o;
	assert(r.xp == 3 && r.yp == 4);
	cout << "test_Point_init passed!" << endl;
}

void test_Point_distance(){
	Point p1(0,0), p2(5,0);
	assert(p1.distance(p2) == 5.0);
	p2.set_point(3,4);
	assert(p1.distance(p2) == 5.0);
	p2.set_point(-3,-4);
	assert(p1.distance(p2) == 5.0);
	p1.set_point(1,1);
	p2.set_point(4,5);
	assert(p1.distance(p2) == 5.0);
	cout << "test_Point_distance passed!" << endl;
}

void test_Vector2D_init(){
	stringstream output;
	Vector2D v;
	assert(v.xv == 0 && v.yv == 0);
	assert(v.p.xp == 0 && v.p.yp == 0);
	Vector2D j(Point(3,4), 1.1, 2.2);
	assert(j.xv == 1.1 && j.yv == 2.2);
	assert(j.p.xp == 3 && j.p.yp == 4);
	v.set_vector(Point(1,2), 2.3, 2.5);
	assert(v.xv == 2.3 && v.yv == 2.5);
	assert(v.p.xp == 1 && v.p.yp == 2);
	Vector2D p = v;
	assert(p.xv == 2.3 && p.yv == 2.5);
	assert(p.p.xp == 1 && p.p.yp == 2);
	Vector2D w(3, 3.4);
	assert(w.xv == 3 && w.yv == 3.4);
	assert(w.p.xp == 0 && w.p.yp == 0);
	v = w;
	assert(v.xv == 3 && v.yv == 3.4);
	assert(v.p.xp == 0 && v.p.yp == 0);
	Vector2D k(v);
	assert(k.xv == 3 && k.yv == 3.4);
	assert(k.p.xp == 0 && k.p.yp == 0);
	k.set_vector(p);
	assert(k.xv == 2.3 && k.yv == 2.5);
	assert(p.p.xp == 1 && p.p.yp == 2);
	output << k;
	string str;
	output >> str;
	assert(str.compare("(2.3,2.5)@(1,2)") == 0);
	Vector2D e = make_horiz_vector(3);
	assert(e.xv == 1 && e.yv == 0);
	assert(e.p.xp == 0 && e.p.yp == 3);
	e = make_vert_vector(3);
	assert(e.xv == 0 && e.yv == 1);
	assert(e.p.xp == 3 && e.p.yp == 0);
	cout << "test_Vector2D passed!" << endl;
}

void test_Vector2D_p2p_vector(){
	Point p1(0,0), p2(2,2);
	Vector2D v = p2p_vector(p1, p2);
	assert(v.xv == 2 && v.yv == 2);
	assert(v.p.xp == 0 && v.p.yp == 0);
	p2.set_point(-2,2);
	v = p2p_vector(p1, p2);
	assert(v.xv == -2 && v.yv == 2);
	assert(v.p.xp == 0 && v.p.yp == 0);
	p1.set_point(3,4);
	v = p2p_vector(p1, p2);
	assert(v.xv == -5 && v.yv == -2);
	assert(v.p.xp == 3 && v.p.yp == 4);
	cout << "test_Vector2D_p2p_vector passed!" << endl;
}

void test_Vector2D_normalize(){
	Vector2D v(5,5);
	v.normalize();
	assert(v.xv == 5.0/sqrt(50.0) && v.yv == 5.0/sqrt(50.0));
	assert(v.p.xp == 0 && v.p.yp == 0);
	v.set_vector(1,3);
	v.normalize();
	assert(v.xv == 1.0/sqrt(10.0) && v.yv == 3.0/sqrt(10.0));
	assert(v.p.xp == 0 && v.p.yp == 0);
	v.set_vector(-4,27);
	v.normalize();
	assert(v.xv == -4.0/sqrt(745.0) && v.yv == 27.0/sqrt(745.0));
	assert(v.p.xp == 0 && v.p.yp == 0);
	cout << "test_Vector2D_normalize passed!" << endl;
}

void test_Vector2D_dot_prod(){
	Vector2D v1(0,5), v2(3,0);
	assert(v1.dot_prod(v2) == 0);
	v1.set_vector(5,0);
	assert(v1.dot_prod(v2) == 15);
	v1.set_vector(-2,-2);
	assert(v1.dot_prod(v2) == -6);
	cout << "test_Vector2D_dot_prod passed!" << endl;
}

void test_Vector2D_reflect(){
	Vector2D x_axis = make_horiz_vector(0), y_axis = make_vert_vector(0),
		v(Point(1,1),1,1);
	v.reflect(y_axis);
	assert(v.xv == -1 && v.yv == 1);
	assert(v.p.xp == -1 && v.p.yp == 1);
	v.set_vector(Point(-1,1), 1, 1);
	v.reflect(y_axis);
	assert(v.xv == -1 && v.yv == 1);
	assert(v.p.xp == 1 && v.p.yp == 1);
	v.set_vector(Point(1,1), 1, 3);
	v.reflect(x_axis);
	assert(v.xv == 1 && v.yv == -3);
	assert(v.p.xp == 1 && v.p.yp == -1);
	v.set_vector(Point(1,3), 1, 3);
	v.reflect(y_axis);
	assert(v.xv == -1 && v.yv == 3);
	assert(v.p.xp == -1 && v.p.yp == 3);
	v.set_vector(Point(3,1),1,-1);
	Vector2D v2(Point(1,1), 1, 1);
	v.reflect(v2);
	assert(v.xv == -1 && v.yv == 1);
	assert(v.p.xp == 1 && v.p.yp == 3);
	cout << "test_Vector2D_reflect passed!" << endl;
}