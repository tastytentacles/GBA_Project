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


gen_obj* _ID_self;
bool _up;
bool _down;
bool _left;
bool _right;
float _speed = 0.25;
float _speed_cap = 2.0;
float _fricton_facter = 1.2;
float _speed_x;
float _speed_y;
float _rel_x;
float _rel_y;

void edge_limiter() {
	if (_rel_x + _speed_x < 0 ||
		_rel_x + _speed_x + _ID_self->_box._width > 240) {
		_speed_x = 0;
	}

	if (_rel_y + _speed_y < 0 ||
		_rel_y + _speed_y + _ID_self->_box._height > 160) {
		_speed_y = 0;
	}
}

void player_friction() {
	if (fabsf(_speed_x) > 0.01) {
		_speed_x /= _fricton_facter;
	}
	else {
		_speed_x = 0;
	}

	if (fabsf(_speed_y) > 0.01) {
		_speed_y /= _fricton_facter;
	}
	else {
		_speed_y = 0;
	}
}

void player_b(gen_obj* self) {
	if (_ID_self == NULL) {
		_ID_self = self;
	}

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

	player_friction();

	edge_limiter();

	_rel_x += _speed_x;
	_rel_y += _speed_y;

	self->_pos._x = slashRound(_rel_x);
	self->_pos._y = slashRound(_rel_y);
}