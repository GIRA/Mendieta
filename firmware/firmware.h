#include "USB_HID.h"
#include "int_defs_C18.h"


#define SERVO_0		 LATBbits.LATB0
#define SERVO_1		 LATBbits.LATB1
#define PWM_0		 LATBbits.LATB7
#define PWM_1		 LATBbits.LATB4

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

int tick = 0;
int lastSendTime = 0;

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

// PWM
SHORT pwm[2] = {0, 0};
SHORT pwm_last[2] = {0, 0};
BYTE pwm_active[2] = {0, 0};
BYTE pwm_current = 0;
