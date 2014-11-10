
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>


extern void myfunc(int* answer);
// need "extern" because the function body is in an external .s file

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	irqInit();
	irqEnable(IRQ_VBLANK);

	// generic setup function
	consoleDemoInit();

	// ansi escape sequence to clear screen and home cursor
	// /x1b[line;columnH
	iprintf("\x1b[2J");


	int x = 0;

	// main loop
	while (1) 
	{
		
		myfunc(&x); // this should update the value of x using the asm function
		


		// ansi escape sequence to set print co-ordinates
		// /x1b[line;columnH
		iprintf("\x1b[10;10Hresult = %d",x);




		VBlankIntrWait();
	}
}


