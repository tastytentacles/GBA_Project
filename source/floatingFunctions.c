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

void test_bahaviour(obj* self) {
	self->_pos._x += 1;
	self->_pos._y += 1;
}

// 	if ((_speed_x > _speed_cap) || (_speed_x < -_speed_cap)) {
// 		_speed_x = (fabsf(_speed_x) / _speed_x) * _speed_cap; }
// 	if ((_speed_y > _speed_cap) || (_speed_y < -_speed_cap)) {
// 		_speed_y = (fabsf(_speed_y) / _speed_y) * _speed_cap; }

float _speed = 0.25;
float _fricton_facter = 1.2;
// float _speed_cap = 2.0;

void edge_limiter(agent* _self) {
	float _x_c = _self->_x_r + _self->_self._box._x;
	if (_x_c + _self->_x_s < 0 ||
		_x_c + _self->_x_s + _self->_self._box._width > 240) {
		_self->_x_s = 0;
	}

	float _y_c = _self->_y_r + _self->_self._box._y;
	if (_y_c + _self->_y_s < 0 ||
		_y_c + _self->_y_s + _self->_self._box._height > 160) {
		_self->_y_s = 0;
	}
}

void player_friction(agent* _self) {
	if (fabsf(_self->_x_s) > 0.01) {
		_self->_x_s /= _fricton_facter;
	}
	else {
		_self->_x_s = 0;
	}

	if (fabsf(_self->_y_s) > 0.01) {
		_self->_y_s /= _fricton_facter;
	}
	else {
		_self->_y_s = 0;
	}
}

void player_script(agent* self) {
	scanKeys();
	u16 _keyDown = keysDown();
	u16 _keyUp = keysUp();

	if ((_keyDown >> 6) == 1)
		{ self->_up = 1; }
	if ((_keyDown >> 7) == 1)
		{ self->_down = 1; }
	if ((_keyDown >> 5) == 1)
		{ self->_left = 1; }
	if ((_keyDown >> 4) == 1)
		{ self->_right = 1; }

	if ((_keyUp >> 6) == 1)
		{ self->_up = 0; }
	if ((_keyUp >> 7) == 1)
		{ self->_down = 0; }
	if ((_keyUp >> 5) == 1)
		{ self->_left = 0; }
	if ((_keyUp >> 4) == 1)
		{ self->_right = 0; }

	self->_x_s += (self->_right - self->_left) * _speed;
	self->_y_s += (self->_down - self->_up) * _speed;

	edge_limiter(self);

	player_friction(self);

	self->_x_r += self->_x_s;
	self->_y_r += self->_y_s;

	self->_self._pos._x = slashRound(self->_x_r);
	self->_self._pos._y = slashRound(self->_y_r);
}


void dave_script(agent* self) {
	// if ()
}