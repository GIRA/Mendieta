#include "USB_HID.h"
#include "int_defs_C18.h"
#include <delays.h>


void setup(void);
void loop(void);
void processUsbCommands(void);
void executePinValue(void);
void executePinMode(void);
void executeServoPWM(void);
void executeActivateServo(void);
void executeContinuousServo(void);
WORD_VAL ReadADC(short);
void sendAnalogInputs(void);
void handleTMR0Interrupt(void);

#pragma code HIGH_INTERRUPT_VECTOR = 0x08
void High_ISR (void)	{
	_asm goto YourHighPriorityISRCode _endasm
}
#pragma code LOW_INTERRUPT_VECTOR = 0x18
void Low_ISR (void){
	_asm goto YourLowPriorityISRCode _endasm
}
	
#pragma code

#define set_TMR0(x) {TMR0H=(x>>8); TMR0L=(x&0x00FF);}
#define start_TMR0 T0CONbits.TMR0ON=1;


#define SERVO_0		 LATBbits.LATB0
#define SERVO_1		 LATBbits.LATB1

// NORMAL SERVOS
UINT16 servo_pulse[2] = {0, 0};
UINT16 servo_lastp[2] = {0, 0};
BYTE servo_active[2] = {0, 0};
BYTE servo_current = 0;

// CONTINUOUS SERVOS
SHORT servo_speed[2] = {0, 0};
SHORT servo_wait[2] = {0, 0};
SHORT servo_skip[2] = {0, 0};
SHORT servo_cycles[2] = {0, 0};
SHORT servo_skipped[2] = {0, 0};
SHORT cycles = 2; // How many cycles the servo *must* perform

#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode(){
	#if defined(USB_INTERRUPT)
		USBDeviceTasks();
    #endif
	
	// TMR
	if (TMR0_flag)  // ISR de la interrupcion de TMR0
	{
		/*
		counter++;
		if (counter >= 45)
		{
			SERVO_0 = 1 - SERVO_0;
			counter = 0;
		}
		*/
		handleTMR0Interrupt();
		TMR0_flag=0;		
	}
}
#pragma interruptlow YourLowPriorityISRCode
void YourLowPriorityISRCode(){}
#pragma code

UINT16 regularServo(int index)
{
	BYTE high = 0;
	if (servo_active[index] == 1 
		&& servo_wait[index] == 0
		&& (servo_skip[index] == 0
			|| (servo_skipped[index] == 0 
				&& servo_cycles[index] < cycles)))
	{
		servo_cycles[index] = servo_cycles[index] + 1;
		servo_skipped[index] = 0;
		switch (index)
		{
			case 0: 
				SERVO_0 = 1 - SERVO_0; 
				high = SERVO_0; 
				break;
			case 1: 
				SERVO_1 = 1 - SERVO_1; 
				high = SERVO_1; 
				break;
			default: // Invalid servo
				// Full cycle
				return 65536 - 7500;
		}
		if (high)
		{
			servo_lastp[index] = servo_pulse[index];
			return 65536 - (UINT16)(servo_pulse[index] * 3);
		}
		else 
		{
			servo_current = (servo_current + 1) % 8;
			return 65536 - 7500 + (UINT16)(servo_lastp[index] * 3);			
		}
	}
	else
	{
		if (servo_wait[index] > 0)
		{
			servo_wait[index] = servo_wait[index] - 1;
		}

		if (servo_skipped[index] < servo_skip[index])
		{
			servo_skipped[index] = servo_skipped[index] + 1;
			servo_cycles[index] = 0;
		}
		else
		{
			servo_skipped[index] = 0;
		}
		servo_current = (servo_current + 1) % 8;
		return 65536 - 7500;
	}
}

void handleTMR0Interrupt(void)
{
	UINT16 TMR0_ini;
	switch(servo_current)
	{
		case 0:
			TMR0_ini = regularServo(0);
			break;
		case 1:			
			TMR0_ini = regularServo(1);
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			TMR0_ini = 65536 - 7500;
			servo_current = (servo_current + 1) % 8;
			break;
		default:
			break;
	}
	set_TMR0(TMR0_ini);
}

int tick = 0;

void delay(void)
{
	int i;
	for (i=0; i<=1; i++)
	 {
	      Delay10KTCYx(250);   // Delay of 10000*250 Cycles
	 }
}

WORD_VAL ReadADC(short analog)
{
    WORD_VAL w;

	// mInitPot();
	ADCON0=(analog<<2)|1;
	ADCON2=0x3C;
	ADCON2bits.ADFM = 1;


    ADCON0bits.GO = 1;              // Start AD conversion
    while(ADCON0bits.NOT_DONE);     // Wait for conversion

    w.v[0] = ADRESL;
    w.v[1] = ADRESH;
 
    return w;
}

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

		tick++;	  
        loop();
    }
	
}

void setup(void)
{
	// PORT modes
	TRISA = 0x00;
	TRISB = 0x00;
	TRISD = 0x00;

	// Interrupts and TMR0
	T0CON = 0b00000001; // Prescaler 1:4
 	enable_global_ints; enable_TMR0_int;
 	start_TMR0;
}


void loop(void)
{
	processUsbCommands();
}

int lastSendTime = 0;
void send(void)
{
	WORD_VAL w;
	if (tick - lastSendTime < 100) return;
	lastSendTime = tick;

	ToSendDataBuffer[0] = PORTA;
	ToSendDataBuffer[1] = PORTD;
	ToSendDataBuffer[2] = PORTB;

	
	sendAnalogInputs();

	// Transmit the response to the host
    if(!HIDTxHandleBusy(USBInHandle))
	{
		USBInHandle = HIDTxPacket(HID_EP,(BYTE*)&ToSendDataBuffer[0],64);
	}
}

// Process USB commands
void processUsbCommands(void)
{   
    // Check if we are in the configured state; otherwise just return
    if((USBDeviceState < CONFIGURED_STATE) || (USBSuspendControl == 1))
    {
	    // We are not configured
	    return;
	}

	// Check if data was received from the host.
    if(!HIDRxHandleBusy(USBOutHandle))
    {   
		// Command mode    
        switch(ReceivedDataBuffer[0])
		{
			case 0x00:  // RQ_PIN_MODE (PIN, MODE)
				executePinMode();
				break;
			case 0x01:	// RQ_PIN_VALUE (PIN, VAL)
				executePinValue();
				break;   	
			case 0x02:  // RQ_SERVO_PWM (PIN, PULSE)
				executeServoPWM();
				break;
			case 0x03:	// RQ_ACTIVATE_SERVO (PIN, ACTIVE)
				executeActivateServo();
				break;
			case 0x04:  // RQ_CONTINUOUS_SERVO (PIN, DIR, SPEED)
				executeContinuousServo();
				break;
            default:	// Unknown command received
           		break;
		}
        // Re-arm the OUT endpoint for the next packet
        USBOutHandle = HIDRxPacket(HID_EP,(BYTE*)&ReceivedDataBuffer,64);
  	}

	send();
}

void executePinValue(void)
{
	int pin = ReceivedDataBuffer[1];
	int value = ReceivedDataBuffer[2];
	
	switch(pin)
	{
		// Transcript clear.
		// (2 to: 40) with:
		// #(a0 a1 a2 a3 a4 a5 e0 e1 e2
		// x x x a6 c0 c1 c2 x d0 d1
		// d2 d3 c4 c5 c6 c7 d4 d5 d6 d7
		// x x b0 b1 b2 b3 b4 b5 b6 b7) 
		// do: [:pinNumber :pinName |
		// 	pinName ~= #x ifTrue: [| str |
		// 		str := '		case {1}:
		// 			LAT{2}bits.LAT{3} = value;
		// 			break;'
		// 			format: {
		// 				pinNumber.
		// 				pinName asUppercase first asString.
		// 				pinName asUppercase
		// 			}.
		// 		Transcript show: str; cr]].
		case 2:
			LATAbits.LATA0 = value;
			break;
		case 3:
			LATAbits.LATA1 = value;
			break;
		case 4:
			LATAbits.LATA2 = value;
			break;
		case 5:
			LATAbits.LATA3 = value;
			break;
		case 6:
			LATAbits.LATA4 = value;
			break;
		case 7:
			LATAbits.LATA5 = value;
			break;
		case 8:
			LATEbits.LATE0 = value;
			break;
		case 9:
			LATEbits.LATE1 = value;
			break;
		case 10:
			LATEbits.LATE2 = value;
			break;
		case 14:
			LATAbits.LATA6 = value;
			break;
		case 15:
			LATCbits.LATC0 = value;
			break;
		case 16:
			LATCbits.LATC1 = value;
			break;
		case 17:
			LATCbits.LATC2 = value;
			break;
		case 19:
			LATDbits.LATD0 = value;
			break;
		case 20:
			LATDbits.LATD1 = value;
			break;
		case 21:
			LATDbits.LATD2 = value;
			break;
		case 22:
			LATDbits.LATD3 = value;
			break;
		case 23:
			// RC4 input pin only
			break;
		case 24:
			// RC5 input pin only
			break;
		case 25:
			LATCbits.LATC6 = value;
			break;
		case 26:
			LATCbits.LATC7 = value;
			break;
		case 27:
			LATDbits.LATD4 = value;
			break;
		case 28:
			LATDbits.LATD5 = value;
			break;
		case 29:
			LATDbits.LATD6 = value;
			break;
		case 30:
			LATDbits.LATD7 = value;
			break;
		case 33:
			LATBbits.LATB0 = value;
			break;
		case 34:
			LATBbits.LATB1 = value;
			break;
		case 35:
			LATBbits.LATB2 = value;
			break;
		case 36:
			LATBbits.LATB3 = value;
			break;
		case 37:
			LATBbits.LATB4 = value;
			break;
		case 38:
			LATBbits.LATB5 = value;
			break;
		case 39:
			LATBbits.LATB6 = value;
			break;
		case 40:
			LATBbits.LATB7 = value;
			break;
		default: // Invalid pin
			break;
	}
}

void executePinMode(void)
{
	int pin = ReceivedDataBuffer[1];
	int value = ReceivedDataBuffer[2];
	
	switch (pin)
	{
		// Autogenerated with Squeak:
		// ==========================
		// Transcript clear.
		// (2 to: 40) with:
		// #(a0 a1 a2 a3 a4 a5 e0 e1 e2
		// x x x a6 c0 c1 c2 x d0 d1
		// d2 d3 c4 c5 c6 c7 d4 d5 d6 d7
		// x x b0 b1 b2 b3 b4 b5 b6 b7) 
		// do: [:pinNumber :pinName |
		// 	pinName ~= #x ifTrue: [| str |
		// 		str := '		case {1}:
		// 			TRIS{2}bits.R{3} = value;
		// 			break;'
		// 			format: {
		// 				pinNumber.
		// 				pinName asUppercase first asString.
		// 				pinName asUppercase
		// 			}.
		// 		Transcript show: str; cr]]
		case 2:
			TRISAbits.RA0 = value;
			break;
		case 3:
			TRISAbits.RA1 = value;
			break;
		case 4:
			TRISAbits.RA2 = value;
			break;
		case 5:
			TRISAbits.RA3 = value;
			break;
		case 6:
			TRISAbits.RA4 = value;
			break;
		case 7:
			TRISAbits.RA5 = value;
			break;
		case 8:
			TRISEbits.RE0 = value;
			break;
		case 9:
			TRISEbits.RE1 = value;
			break;
		case 10:
			TRISEbits.RE2 = value;
			break;
		case 14:
			TRISAbits.RA6 = value;
			break;
		case 15:
			TRISCbits.RC0 = value;
			break;
		case 16:
			TRISCbits.RC1 = value;
			break;
		case 17:
			TRISCbits.RC2 = value;
			break;
		case 19:
			TRISDbits.RD0 = value;
			break;
		case 20:
			TRISDbits.RD1 = value;
			break;
		case 21:
			TRISDbits.RD2 = value;
			break;
		case 22:
			TRISDbits.RD3 = value;
			break;
		case 23:
			//TRISCbits.RC4 = value;
			break;
		case 24:
			//TRISCbits.RC5 = value;
			break;
		case 25:
			TRISCbits.RC6 = value;
			break;
		case 26:
			TRISCbits.RC7 = value;
			break;
		case 27:
			TRISDbits.RD4 = value;
			break;
		case 28:
			TRISDbits.RD5 = value;
			break;
		case 29:
			TRISDbits.RD6 = value;
			break;
		case 30:
			TRISDbits.RD7 = value;
			break;
		case 33:
			TRISBbits.RB0 = value;
			break;
		case 34:
			TRISBbits.RB1 = value;
			break;
		case 35:
			TRISBbits.RB2 = value;
			break;
		case 36:
			TRISBbits.RB3 = value;
			break;
		case 37:
			TRISBbits.RB4 = value;
			break;
		case 38:
			TRISBbits.RB5 = value;
			break;
		case 39:
			TRISBbits.RB6 = value;
			break;
		case 40:
			TRISBbits.RB7 = value;
			break;
		default: // Invalid pin
			break;
	}
}


void sendAnalogInputs(void)
{
	WORD_VAL w;
	// Autogenerated with Squeak:
	// ##########################
	// pins := #(A0 A1 A2 A3 A5 E0 E1 E2 B2 B3 B1 B4 B0) collect: [:each | 'TRIS', each].
	// analogs := (0 to: 12).
	// analogs with: pins do: [:an :tris || str |
	// 	str := '	if ({1}bits.{2} == 1)
	// 	\{
	// 		w = ReadADC({3});
	// 		ToSendDataBuffer[{4}] = w.v[0];
	// 		ToSendDataBuffer[{5}] = w.v[1];
	// 	\}' format: {
	// 		tris first: 5.
	// 		tris.
	// 		an.
	// 		an * 2 + 3.
	// 		an * 2 + 4
	// 	}.
	// 	Transcript show: str; cr.
	// ]

	if (TRISAbits.TRISA0 == 1)
	{
		w = ReadADC(0);
		ToSendDataBuffer[3] = w.v[0];
		ToSendDataBuffer[4] = w.v[1];
	}
	if (TRISAbits.TRISA1 == 1)
	{
		w = ReadADC(1);
		ToSendDataBuffer[5] = w.v[0];
		ToSendDataBuffer[6] = w.v[1];
	}
	if (TRISAbits.TRISA2 == 1)
	{
		w = ReadADC(2);
		ToSendDataBuffer[7] = w.v[0];
		ToSendDataBuffer[8] = w.v[1];
	}
	if (TRISAbits.TRISA3 == 1)
	{
		w = ReadADC(3);
		ToSendDataBuffer[9] = w.v[0];
		ToSendDataBuffer[10] = w.v[1];
	}
	if (TRISAbits.TRISA5 == 1)
	{
		w = ReadADC(4);
		ToSendDataBuffer[11] = w.v[0];
		ToSendDataBuffer[12] = w.v[1];
	}
	if (TRISEbits.TRISE0 == 1)
	{
		w = ReadADC(5);
		ToSendDataBuffer[13] = w.v[0];
		ToSendDataBuffer[14] = w.v[1];
	}
	if (TRISEbits.TRISE1 == 1)
	{
		w = ReadADC(6);
		ToSendDataBuffer[15] = w.v[0];
		ToSendDataBuffer[16] = w.v[1];
	}
	if (TRISEbits.TRISE2 == 1)
	{
		w = ReadADC(7);
		ToSendDataBuffer[17] = w.v[0];
		ToSendDataBuffer[18] = w.v[1];
	}
	if (TRISBbits.TRISB2 == 1)
	{
		w = ReadADC(8);
		ToSendDataBuffer[19] = w.v[0];
		ToSendDataBuffer[20] = w.v[1];
	}
	if (TRISBbits.TRISB3 == 1)
	{
		w = ReadADC(9);
		ToSendDataBuffer[21] = w.v[0];
		ToSendDataBuffer[22] = w.v[1];
	}
	if (TRISBbits.TRISB1 == 1)
	{
		w = ReadADC(10);
		ToSendDataBuffer[23] = w.v[0];
		ToSendDataBuffer[24] = w.v[1];
	}
	if (TRISBbits.TRISB4 == 1)
	{
		w = ReadADC(11);
		ToSendDataBuffer[25] = w.v[0];
		ToSendDataBuffer[26] = w.v[1];
	}
	if (TRISBbits.TRISB0 == 1)
	{
		w = ReadADC(12);
		ToSendDataBuffer[27] = w.v[0];
		ToSendDataBuffer[28] = w.v[1];
	}
}

void executeServoPWM(void)
{
	int pin = ReceivedDataBuffer[1];
	int valueL = ReceivedDataBuffer[2];
	int valueH = ReceivedDataBuffer[3];

	UINT16 value = (UINT16)valueL | ((UINT16)valueH << 8);
	
	switch(pin)
	{
		case 33:
			servo_pulse[0] = value;
			break;
		case 34:
			servo_pulse[1] = value;
			break;
		default: // Invalid pin
			break;
	}

}

void executeActivateServo(void)
{
	int pin = ReceivedDataBuffer[1];
	int active = ReceivedDataBuffer[2];

	switch(pin)
	{
		case 33:
			servo_active[0] = active;
			break;
		case 34:
			servo_active[1] = active;
			break;
		default: // Invalid pin
			break;
	}

}

void continuousServo(int index, int direction, int speed)
{
	if (servo_wait[index] == 0)
	{
		if (direction == 0)
		{
			servo_speed[index] = 0;
			servo_wait[index] = 15;
		}
		else 
		{
			if ((direction > 0 && servo_speed[index] < 0)
				|| (direction < 0 && servo_speed[index] > 0))
			{
				servo_wait[index] = 15;
			}
			servo_speed[index] = speed * (direction > 0 ? 1 : -1);
			servo_skip[index] = (255 - speed)/20;
		}

		if (servo_speed[index] == 0)
		{
			servo_active[index] = 0;
		}
		else if (servo_speed[index] < 0)
		{
			servo_pulse[index] = 500;
			servo_active[index] = 1;
		}
		else if (servo_speed[index] > 0)
		{
			servo_pulse[index] = 2500;
			servo_active[index] = 1;
		}				
	}
}

void executeContinuousServo(void)
{
	int pin = ReceivedDataBuffer[1];
	int direction = ReceivedDataBuffer[2];
	int speed = ReceivedDataBuffer[3];

	direction--; // -1 .. 0 .. 1

	switch(pin)
	{
		case 33:
			continuousServo(0, direction, speed);
			break;
		case 34:
			continuousServo(1, direction, speed);
			break;
		default: // Invalid pin
			break;
	}
}