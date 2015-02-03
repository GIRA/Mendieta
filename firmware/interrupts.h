
#include "firmware.h"
 
#define set_TMR0(x) {TMR0H=(x>>8); TMR0L=(x&0x00FF);}
#define start_TMR0 T0CONbits.TMR0ON=1;

#define set_TMR1(x) {TMR1H=(x>>8); TMR1L=(x&0x00FF);}
#define start_TMR1 T1CONbits.TMR1ON=1;
 
void handleTMR0Interrupt(void);
void handleTMR1Interrupt(void);
