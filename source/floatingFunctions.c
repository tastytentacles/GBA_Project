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


// obj* _ID_self;
// bool _up;s
// bool _down;
// bool _left;
// bool _right;
float _speed = 0.25;
// float _speed_cap = 2.0;
// float _fricton_facter = 1.2;
// float _speed_x;
// float _speed_y;
// float _rel_x;
// float _rel_y;

// void edge_limiter() {
// 	float _c_x = _rel_x + _ID_self->_box._x;
// 	if (_c_x + _speed_x < 0 ||
// 		_c_x + _speed_x + _ID_self->_box._width > 240) {
// 		_speed_x = 0;
// 	}

// 	float _c_y = _rel_y + _ID_self->_box._y;
// 	if (_c_y + _speed_y < 0 ||
// 		_c_y + _speed_y + _ID_self->_box._height > 160) {
// 		_speed_y = 0;
// 	}
// }

// void player_friction() {
// 	if (fabsf(_speed_x) > 0.01) {
// 		_speed_x /= _fricton_facter;
// 	}
// 	else {
// 		_speed_x = 0;
// 	}

// 	if (fabsf(_speed_y) > 0.01) {
// 		_speed_y /= _fricton_facter;
// 	}
// 	else {
// 		_speed_y = 0;
// 	}
// }

// void player_b(obj* self) {
// 	if (_ID_self == NULL) {
// 		_ID_self = self;

// 		_rel_x = self->_pos._x;
// 		_rel_y = self->_pos._y;
// 	}

// 	scanKeys();
// 	u16 _keyDown = keysDown();
// 	u16 _keyUp = keysUp();

// 	if ((_keyDown >> 6) == 1)
// 		{ _up = 1; }
// 	if ((_keyDown >> 7) == 1)
// 		{ _down = 1; }
// 	if ((_keyDown >> 5) == 1)
// 		{ _left = 1; }
// 	if ((_keyDown >> 4) == 1)
// 		{ _right = 1; }

// 	if ((_keyUp >> 6) == 1)
// 		{ _up = 0; }
// 	if ((_keyUp >> 7) == 1)
// 		{ _down = 0; }
// 	if ((_keyUp >> 5) == 1)
// 		{ _left = 0; }
// 	if ((_keyUp >> 4) == 1)
// 		{ _right = 0; }

// 	_speed_x += (_right - _left) * _speed;
// 	_speed_y += (_down - _up) * _speed;

// 	if ((_speed_x > _speed_cap) || (_speed_x < -_speed_cap)) {
// 		_speed_x = (fabsf(_speed_x) / _speed_x) * _speed_cap; }
// 	if ((_speed_y > _speed_cap) || (_speed_y < -_speed_cap)) {
// 		_speed_y = (fabsf(_speed_y) / _speed_y) * _speed_cap; }

// 	player_friction();

// 	edge_limiter();

// 	_rel_x += _speed_x;
// 	_rel_y += _speed_y;

// 	self->_pos._x = slashRound(_rel_x);
// 	self->_pos._y = slashRound(_rel_y);
// }



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

	self->_x_r += self->_x_s;
	self->_y_r += self->_y_s;

	self->_self._pos._x = slashRound(self->_x_r);
	self->_self._pos._y = slashRound(self->_y_r);
}