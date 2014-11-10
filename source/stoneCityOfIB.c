#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "azathoth.h"
#include "bones.h"


int main(void) {
	irqInit();
	irqEnable(IRQ_VBLANK);
	ibRise();

	setMapBox(5, 5, 5, 5, 31);
	setMapBox(6, 6, 3, 3, 0);

	setMapBox(16, 9, 7, 7, 31);
	setMapBox(17, 10, 5, 5, 0);

	int loop_time = 0;
	int loop_step = 0;
	unsigned short* loop_point = (unsigned short*) 0x05000000;
	extern unsigned short rainbow[7];

	firstScreem();

	while (1) {
		loop_time += 1;

		if (loop_time > 4) {
			loop_step += 1;
			loop_time = 0;
		}

		if (loop_step > 6) {
			loop_step = 0;
		}

		tentacle();

		loop_point[0] = rainbow[loop_step];

		VBlankIntrWait();
	}
}