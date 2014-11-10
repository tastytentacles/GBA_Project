/*	   ____                            ___           _ _ _ _               
	  / __ \  /\/\   __ _ _ __ __ _   /   \_____   _(_) | (_) ___ _ __ ___ 
	 / / _` |/    \ / _` | '__/ _` | / /\ / _ \ \ / / | | | |/ _ \ '__/ __|
	| | (_| / /\/\ \ (_| | | | (_| |/ /_//  __/\ V /| | | | |  __/ |  \__ \
	 \ \__,_\/    \/\__,_|_|  \__, /___,' \___| \_/ |_|_|_|_|\___|_|  |___/
	  \____/                     |_|                                       
*/

#include "shoggoth.h"


gen_obj infiniteVoid[64];
void addGenObject(int tX, int tY, int tSprite, int tIndex) {
	gen_obj voidObj = {
		._pos = {
			._x = tX,
			._y = tY
		},
		._sprite_ID = tSprite,
		._pointer = 0x07000000 + (8 * tIndex)
	};

	infiniteVoid[tIndex] = voidObj;
}

void addBehaviour(void (*_pass_in_function), int tIndex) {
	infiniteVoid[tIndex]._dave = _pass_in_function;
}

void deleteGenObject(int tIndex){
	gen_obj voidObj;
	infiniteVoid[tIndex] = voidObj;
}

void clearTheDead() {
	int n;
	for (n = 0; n < 64; n++) {
		if (infiniteVoid[n]._blackSpot) { deleteGenObject(n); }}
}


extern void player_b(gen_obj* self);
void firstScreem() {
	addGenObject(8, 8, 1, 0);
	addGenObject(16, 32, 1, 1);
	addGenObject(32, 32, 1, 2);

	addBehaviour(player_b, 0);
}

void tentacle() {
	unsigned short* objA;

	int n;
	for (n = 0; n < 64; n++) {
		if (infiniteVoid[n]._pointer != 0) {
			objA = (unsigned char*) infiniteVoid[n]._pointer;
			objA[0] = ((infiniteVoid[n]._pos._y << 0));
			objA[1] = ((infiniteVoid[n]._pos._x << 0));
			objA[2] = ((infiniteVoid[n]._sprite_ID << 0));
			if (infiniteVoid[n]._dave != NULL) {
				infiniteVoid[n]._dave(&infiniteVoid[n]);
			}
		}
	}

	objA = NULL;
	free(objA);
}

// gen_obj obj = {
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
	// ._pointer = 0x07000000 + 8,
	// ._sprite_ID = 1
// };