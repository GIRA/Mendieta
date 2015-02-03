/*
 * INTERRUPTS & TIMERS
 */ 
#include "interrupts.h"


#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode(){
	#if defined(USB_INTERRUPT)
		USBDeviceTasks();
    #endif

	// TMR
	if (TMR0_flag)  // ISR de la interrupcion de TMR0
	{
		handleTMR0Interrupt();
		TMR0_flag = 0;
	}
	if (TMR1_flag)
	{	
		handleTMR1Interrupt();
		TMR1_flag = 0;
	}
}
#pragma interruptlow YourLowPriorityISRCode
void YourLowPriorityISRCode(){}
#pragma code HIGH_INTERRUPT_VECTOR = 0x08
void High_ISR (void)	{
	_asm goto YourHighPriorityISRCode _endasm
}
#pragma code LOW_INTERRUPT_VECTOR = 0x18
void Low_ISR (void){
	_asm goto YourLowPriorityISRCode _endasm
}	
#pragma code


void handleTMR1Interrupt(void)
{
	UINT16 TMR1_ini;

	switch (pwm_current)
	{
		case 0:
			if (pwm_active[0]) PWM_0 = 1;
			if (pwm_active[1]) PWM_1 = 1;
			pwm_last[0] = pwm[0];
			pwm_last[1] = pwm[1];
			TMR1_ini = 65536 - (pwm[0] < pwm[1] ? pwm[0] : pwm[1]);
			pwm_current++;
			break;
		case 1:
			if (pwm_last[0] < pwm_last[1])
			{
				if (pwm_active[0]) PWM_0 = 0;
				TMR1_ini = 65536 - pwm_last[1] + pwm_last[0];
			}
			else
			{
				if (pwm_active[1]) PWM_1 = 0;
				TMR1_ini = 65536 - pwm_last[0] + pwm_last[1];
			}
			pwm_current++;
			break;
		case 2:
			if (pwm_last[0] >= pwm_last[1])
			{
				if (pwm_active[0]) PWM_0 = 0;
				TMR1_ini = 65536 - 3000 + pwm_last[0];
			}
			else
			{
				if (pwm_active[1]) PWM_1 = 0;
				TMR1_ini = 65536 - 3000 + pwm_last[1];
			}
			pwm_current = 0;
			break;
		default:
			break;
	}
	/*
	if (pwm_active[0])
	{
		PWM_0 = 1 - PWM_0;
		if (PWM_0)
		{
			last_pwm[0] = pwm[0];
			TMR1_ini = 65536 - pwm[0];		
		}
		else
		{
			TMR1_ini = 65536 - 3000 + last_pwm[0];
		}
	}
	else
	{
		TMR1_ini = 65536 - 3000;
		if (pwm[0] > 1500)
		{
			PWM_0 = 1;
		}
		else
		{
			PWM_0 = 0;
		}
	}
	*/
	set_TMR1(TMR1_ini);
}


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
