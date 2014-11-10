/*	   ____                            ___           _ _ _ _               
	  / __ \  /\/\   __ _ _ __ __ _   /   \_____   _(_) | (_) ___ _ __ ___ 
	 / / _` |/    \ / _` | '__/ _` | / /\ / _ \ \ / / | | | |/ _ \ '__/ __|
	| | (_| / /\/\ \ (_| | | | (_| |/ /_//  __/\ V /| | | | |  __/ |  \__ \
	 \ \__,_\/    \/\__,_|_|  \__, /___,' \___| \_/ |_|_|_|_|\___|_|  |___/
	  \____/                     |_|                                       
*/

#include <gba_input.h>

#include <math.h>

#include "HeadRoom/shoggoth.h"


extern unsigned int slashRound(float q);

void test_bahaviour(gen_obj* self) {
	self->_pos._x += 1;
	self->_pos._y += 1;
}

bool _up;
bool _down;
bool _left;
bool _right;
float _speed = 0.05;
float _speed_cap = 2.0;
float _speed_x;
float _speed_y;
float _rel_x;
float _rel_y;
void player_b(gen_obj* self) {
	scanKeys();
	unsigned int _key_down = keysDown();
	unsigned int _key_up = keysUp();

	switch (_key_down) {
		case KEY_UP :
			_up = 1;
			break;
		case KEY_DOWN :
			_down = 1;
			break;
		case KEY_LEFT :
			_left = 1;
			break;
		case KEY_RIGHT :
			_right = 1;
			break;
	}

	switch (_key_up) {
		case KEY_UP :
			_up = 0;
			break;
		case KEY_DOWN :
			_down = 0;
			break;
		case KEY_LEFT :
			_left = 0;
			break;
		case KEY_RIGHT :
			_right = 0;
			break;
	}

	_speed_x += (_right - _left) * _speed;
	_speed_y += (_down - _up) * _speed;

	if ((_speed_x > _speed_cap) || (_speed_x < -_speed_cap)) {
		_speed_x = (fabsf(_speed_x) / _speed_x) * _speed_cap; }
	if ((_speed_y > _speed_cap) || (_speed_y < -_speed_cap)) {
		_speed_y = (fabsf(_speed_y) / _speed_y) * _speed_cap; }

	_rel_x += _speed_x;
	_rel_y += _speed_y;

	self->_pos._x = slashRound(_rel_x);
	self->_pos._y = slashRound(_rel_y);
}