/*	   ____                            ___           _ _ _ _               
	  / __ \  /\/\   __ _ _ __ __ _   /   \_____   _(_) | (_) ___ _ __ ___ 
	 / / _` |/    \ / _` | '__/ _` | / /\ / _ \ \ / / | | | |/ _ \ '__/ __|
	| | (_| / /\/\ \ (_| | | | (_| |/ /_//  __/\ V /| | | | |  __/ |  \__ \
	 \ \__,_\/    \/\__,_|_|  \__, /___,' \___| \_/ |_|_|_|_|\___|_|  |___/
	  \____/                     |_|                                       
*/

// OMG this is the grossist round ever
unsigned int slashRound(float q) {
	float p1 = (q - (unsigned int) q);
	unsigned int a;
	if (p1 < 0.5) { a = q; }
	else {a = q + 1; }
	return a;
}


void defineSpriteSpace() {
	extern unsigned int omegaSprite[4096];
	unsigned int* spritePoint = (unsigned int*) 0x0600C000;
	int n;
	for (n = 0; n < 4096; n++) {
		spritePoint[n] = omegaSprite[n];
	}
}

void setMapPoint(int _x, int _y, int _set) {
	unsigned short* ap = (unsigned short*) 0x06000000;
	ap = ap + (0x400 * 10);
	int _n = (_y * 32) + _x;
	ap[_n] = _set;
	ap = NULL;
	free(ap);
}

void setMapBox(int _x, int _y, int _width, int _height, int _set) {
	int nx;
	int ny;
	for (nx = 0; nx < _width; nx++) {
		for (ny = 0; ny < _height; ny++) {
			setMapPoint(_x + nx, _y + ny, _set);
		}
	}
}



void ibRise() {
	unsigned short* cp1 = (unsigned short*) 0x4000000;
	unsigned short* cp2 = (unsigned short*) 0x4000004;
	unsigned short* cp3 = (unsigned short*) 0x4000008;
	cp1[0] = ((1 << 6) | (1 << 8) | (0 << 9) | (0 << 10) | (1 << 12));
	cp2[0] = ((1 << 3));
	cp3[0] = ((10 << 8));

	cp1 = NULL;
	free(cp1);
	cp2 = NULL;
	free(cp2);
	cp3 = NULL;
	free(cp3);

	unsigned short* grayScale = (unsigned short*) 0x05000002;
	grayScale[0] = RGB5(0, 0, 0);
	grayScale[1] = RGB5(31, 0, 0);
	grayScale[2] = RGB5(0, 8, 0);
	grayScale[3] = RGB5(0, 31, 0);
	grayScale[4] = RGB5(21, 21, 21);
	grayScale[5] = RGB5(0, 23, 31);
	grayScale[6] = RGB5(10, 0, 10);
	grayScale[7] = RGB5(0, 10, 20);

	unsigned short* sp = (unsigned short*) 0x05000200;
	sp[1] = RGB5(31, 31, 31);
	sp[2] = RGB5(31, 4, 4);
	sp[3] = RGB5(31, 20, 20);
	sp = NULL;
	free(sp);

	defineSpriteSpace();
}