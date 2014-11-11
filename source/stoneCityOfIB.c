#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "HeadRoom/azathoth.h"
#include "HeadRoom/bones.h"


int main(void) {
	irqInit();
	irqEnable(IRQ_VBLANK);
	ibRise();

	setMapBox(10, 5, 10, 10, 1);
	setMapPoint(10, 5, 3);
	setMapPoint(19, 5, 5);
	setMapPoint(10, 14, 67);
	setMapPoint(19, 14, 69);

	setMapBox(11, 5, 8, 1, 4);
	setMapBox(10, 6, 1, 8, 35);
	setMapBox(11, 14, 8, 1, 68);
	setMapBox(19, 6, 1, 8, 37);

	firstScreem();

	while (1) {
		tentacle();

		VBlankIntrWait();
	}
}