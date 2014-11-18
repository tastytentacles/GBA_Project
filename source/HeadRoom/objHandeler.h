/*	   ____                            ___           _ _ _ _               
	  / __ \  /\/\   __ _ _ __ __ _   /   \_____   _(_) | (_) ___ _ __ ___ 
	 / / _` |/    \ / _` | '__/ _` | / /\ / _ \ \ / / | | | |/ _ \ '__/ __|
	| | (_| / /\/\ \ (_| | | | (_| |/ /_//  __/\ V /| | | | |  __/ |  \__ \
	 \ \__,_\/    \/\__,_|_|  \__, /___,' \___| \_/ |_|_|_|_|\___|_|  |___/
	  \____/                     |_|                                       
*/

#include "shoggoth.h"


agent handeler[16];
void addAgent(int tIndex, int tX, int tY, int tSprite, int tSSize) {
	agent _temp = {
		._self = {
			._pos = {
				._x = tX,
				._y = tY
			},
			._sprite_ID = tSprite,
			._sprite_size = tSSize,
			._pointer = 0x07000000 + (8 * tIndex)
		},
		._up = 0,
		._down = 0,
		._left = 0,
		._right = 0,
		._x_r = tX,
		._y_r = tY
	};
	handeler[tIndex] = _temp;
}

void addAgentScript(int tIndex, void (*_pass_in_script))
	{ handeler[tIndex]._script = _pass_in_script; }

void setAgentBox(int tIndex, int tX, int tY, int tWidth, int tHeight) {
	handeler[tIndex]._self._box._x = tX;
	handeler[tIndex]._self._box._y = tY;
	handeler[tIndex]._self._box._width = tWidth;
	handeler[tIndex]._self._box._height = tHeight;
}

// extern void player_b(obj* self);
extern void player_script(agent* self);
extern void dave_script(agent* self);
void stage2() {
	addAgent(0, 112, 75, 1, 1);
	setAgentBox(0, 0, 0, 16, 16);
	addAgentScript(0, player_script);

	addAgent(1, 60, 60, 5, 1);
	setAgentBox(1, 0, 0, 16, 16);
	addAgentScript(1, dave_script);
}

// void deleteGenObject(int tIndex) {
// 	obj voidObj;
// 	infiniteVoid[tIndex] = voidObj;
// }

// void clearTheDead() {
// 	int n;
// 	for (n = 0; n < 64; n++) {
// 		if (infiniteVoid[n]._blackSpot) { deleteGenObject(n); }}
// }

void obj_loop() {
	unsigned short* _hand;

	int n;
	for (n = 0; n < 16; n++) {
		if (handeler[n]._self._pointer != 0) {
			_hand = (unsigned char*) handeler[n]._self._pointer;
			_hand[0] = ((handeler[n]._self._pos._y << 0));
			_hand[1] = ((handeler[n]._self._pos._x << 0) | (handeler[n]._self._sprite_size << 14));
			_hand[2] = ((handeler[n]._self._sprite_ID << 0));
			if (handeler[n]._script != NULL)
				{ handeler[n]._script(&handeler[n]); }
		}
	}

	_hand = NULL;
	free(_hand);
}

// obj obj = {
	// ._pos = {
		// ._x = 32,
		// ._y = 16
	// },
	// ._box = {
	// 	._x = -5,
	// 	._y = -5,
	// 	._width = 10,
	// 	._height = 10
	// },
	// ._sprite_ID = 1,
	// ._sprite_size = 2,
	// ._pointer = 0x07000000 + 8
// };