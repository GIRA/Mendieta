#include "USB_HID.h"
#include "int_defs_C18.h"

#define SERVO_0		 LATBbits.LATB0
#define SERVO_1		 LATBbits.LATB1
#define PWM_0		 LATBbits.LATB7
#define PWM_1		 LATBbits.LATB4

typedef struct {
	UINT16 pulse;
	UINT16 lastPulse;
	BYTE active;
	SHORT speed;
	SHORT wait;
	SHORT skip;
	SHORT cycles;
	SHORT skipped;
} Servo;

void init(void);
void processUsbCommands(void);
void executePinValue(void);
void executePinMode(void);
void executeServoPWM(void);
void executeActivateServo(void);
void executeContinuousServo(void);
void executePWM(void);

WORD_VAL ReadADC(short);
void sendAnalogInputs(void);
void send(void);
void incrementTick(void);


/* INTERRUPTS */
#define set_TMR0(x) {TMR0H=(x>>8); TMR0L=(x&0x00FF);}
#define start_TMR0 T0CONbits.TMR0ON=1;

#define set_TMR1(x) {TMR1H=(x>>8); TMR1L=(x&0x00FF);}
#define start_TMR1 T1CONbits.TMR1ON=1;
 
void handleTMR0Interrupt(void);
void handleTMR1Interrupt(void);

void YourHighPriorityISRCode();
void YourLowPriorityISRCode();
