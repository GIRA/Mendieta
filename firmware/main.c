#include <delays.h>
#include "interrupts.h"
#include "firmware.h"


void setup(void);
void loop(void);

void main(void){

    InitializeSystem();
	
    #if defined(USB_INTERRUPT)
        USBDeviceAttach();
    #endif

	setup();

    while(1)
    {
        #if defined(USB_POLLING)
		// Check bus status and service USB interrupts.
        USBDeviceTasks(); 
        #endif

		incrementTick();
        loop();
    }	
}

void setup(void)
{
	// PORT modes
	TRISA = 0x00;
	TRISB = 0x00;
	TRISD = 0x00;

	// Interrupts and timers
	T0CON = 0b00000001; // Prescaler 1:4
	T1CON = 0b00100000; // Prescaler 1:4
 	enable_global_ints;enable_perif_ints;
	enable_TMR0_int;
	enable_TMR1_int;

 	start_TMR0;
	start_TMR1;
}


void loop(void)
{
	processUsbCommands();
}
