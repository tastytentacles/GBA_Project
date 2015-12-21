#include <gba.h>


void code_init() {
	unsigned short* videopointer = (unsigned short*) 0x4000000;
	videopointer[0] = ((1 << 8));

	unsigned short* bg0pointer = (unsigned short*) 0x4000008;

	unsigned short* palatte = (unsigned short*) 0x05000000;
	palatte[0] = RGB5(1, 1, 1);

	videopointer = NULL; free(videopointer);
	bg0pointer = NULL; free(bg0pointer);
	palatte = NULL; free(palatte);
}

void AgbMain(void){
	//Play a sound on channel 1

	//turn on sound circuit
	REG_SOUNDCNT_X = 0x80;
	//full volume, enable sound 1 to left and right
	REG_SOUNDCNT_L = 0x1177;
	// Overall output ratio - Full
	REG_SOUNDCNT_H = 2;

	REG_SOUND1CNT_L = 0x0056; //sweep shifts=6, increment, sweep time=39.1ms
	REG_SOUND1CNT_H = 0xf780; //duty=50%,envelope decrement
	REG_SOUND1CNT_X = 0x8400; //frequency=0x0400, loop mode

	REG_SOUND2CNT_L = 0x0056;
}

int main(void) {
	irqInit();
	irqEnable(IRQ_VBLANK);
	code_init();

	AgbMain();

	// SoundDriverInit();
	// SoundDriverMode();

	while (1) {
		VBlankIntrWait();
		// SoundDriverVsync();
	}
}
