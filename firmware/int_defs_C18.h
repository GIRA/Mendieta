// Global flags
#define enable_global_ints INTCONbits.GIE=1
#define enable_perif_ints  INTCONbits.PEIE=1
#define disable_global_ints INTCONbits.GIE=0
#define disable_perif_ints  INTCONbits.PEIE=0


// Enable / disable particular interrupts
// Registers: INTCON, INTCON2, INTCON3
// Ints:      TMR0, RB, INT1, INT2  

#define enable_TMR0_int  INTCONbits.TMR0IE=1
#define enable_INT0_int  INTCONbits.INT0E=1
#define enable_RB_int    INTCONbits.RBIE=1

#define enable_INT1_int  INTCON3bits.INT1IE=1
#define enable_INT2_int  INTCON3bits.INT2IE=1

#define disable_TMR0_int  INTCONbits.TMR0IE=0
#define disable_INT0_int  INTCONbits.INT0E=0
#define disable_RB_int    INTCONbits.RBIE=0

#define disable_INT1_int  INTCON3bits.INT1IE=0
#define disable_INT2_int  INTCON3bits.INT2IE=0

#define INT0_low2high INTCON2bits.INTEDG0=1
#define INT1_low2high INTCON2bits.INTEDG1=1
#define INT2_low2high INTCON2bits.INTEDG2=1

#define INT0_high2low INTCON2bits.INTEDG0=0
#define INT1_high2low INTCON2bits.INTEDG1=0
#define INT2_high2low INTCON2bits.INTEDG2=0


// Register: PIE1 
// Ints:  AD /RX /TX / SSP / TMR1 / TMR2 / PSP / CCP

#define enable_AD_int  PIE1bits.ADIE=1
#define enable_RX_int  PIE1bits.RCIE=1
#define enable_TX_int  PIE1bits.TXIE=1
#define enable_SSP_int  PIE1bits.SSPIE=1
#define enable_TMR1_int  PIE1bits.TMR1IE=1
#define enable_TMR2_int  PIE1bits.TMR2IE=1
#define enable_PSP_int  PIE1bits.PSPIE=1
#define enable_CCP1_int  PIE1bits.CCP1IE=1

#define disable_AD_int  PIE1bits.ADIE=0
#define disable_RX_int  PIE1bits.RCIE=0
#define disable_TX_int  PIE1bits.TXIE=0
#define disable_SSP_int  PIE1bits.SSPIE=0
#define disable_TMR1_int  PIE1bits.TMR1IE=0
#define disable_TMR2_int  PIE1bits.TMR2IE=0
#define disable_PSP_int  PIE1bits.PSPIE=0
#define disable_CCP1_int  PIE1bits.CCP2IE=0

// Register: PIE2 
// Ints: CM / EE  / CCP2  / TMR3  / BC
#define enable_CCP2_int  PIE2bits.CCP2IE=1
#define enable_TMR3_int  PIE2bits.TMR3IE=1
#define enable_CM_int    PIE2bits.CMIE=1
#define enable_EE_int    PIE2bits.EEIE=1
#define enable_BC_int    PIE2bits.BCIE=1
#define enable_OSCF_int    PIE2bits.OSCFIE=1
#define enable_HLVD_int    PIE2bits.HLVDIE=1


#define disable_CCP2_int  PIE2bits.CCP2IE=0
#define disable_TMR3_int  PIE2bits.TMR3IE=0
#define disable_CM_int    PIE2bits.CMIE=0
#define disable_EE_int    PIE2bits.EEIE=0
#define disable_BC_int    PIE2bits.BCIE=0
#define disable_OSCF_int  PIE2bits.OSCFIE=0
#define disable_HLVD_int  PIE2bits.HLVDIE=0


// Interrupts flags 
#define TMR0_flag  INTCONbits.TMR0IF
#define INT0_flag  INTCONbits.INT0IF
#define RB_flag    INTCONbits.RBIF
#define INT1_flag  INTCON3bits.INT1IF
#define INT2_flag  INTCON3bits.INT2IF


#define AD_flag  PIR1bits.ADIF
#define RX_flag  PIR1bits.RCIF
#define TX_flag  PIR1bits.TXIF
#define SSP_flag  PIR1bits.SSPIF
#define TMR1_flag  PIR1bits.TMR1IF
#define TMR2_flag  PIR1bits.TMR2IF
#define PSP_flag  PIR1bits.PSPIF
#define CCP1_flag  PIR1bits.CCP1IF

#define CCP2_flag  PIR2bits.CCP2IF
#define TMR3_flag  PIR2bits.TMR3IF
#define CM_flag    PIR2bits.CMIF
#define EE_flag    PIR2bits.EEIF
#define BC_flag    PIR2bits.BCIF
#define OSCF_flag    PIR2bits.OSCFIF
#define HLVD_flag    PIR2bits.HLVDIF


// PRIORIDADES
#define enable_priority_levels   RCONbits.IPEN=1

#define enable_high_ints INTCONbits.GIE=1
#define enable_low_ints  INTCONbits.PEIE=1

#define disable_high_ints INTCONbits.GIE=0
#define disable_low_ints  INTCONbits.PEIE=0

#define set_TMR0_high INTCON2bits.TMR0IP=1
#define set_RB_high INTCON2bits.RBIP=1

#define set_INT1_high INTCON3bits.INT1IP=1
#define set_INT2_high INTCON3bits.INT2IP=1

#define set_TMR0_low INTCON2bits.TMR0IP=0
#define set_RB_low INTCON2bits.RBIP=0
#define set_INT2_low INTCON3bits.INT2IP=0

#define set_AD_high  IPR1bits.ADIP=1
#define set_RX_high  IPR1bits.RCIP=1
#define set_TX_high  IPR1bits.TXIP=1
#define set_SSP_high  IPR1bits.SSPIP=1
#define set_TMR1_high  IPR1bits.TMR1IP=1
#define set_TMR2_high  IPR1bits.TMR2IP=1
#define set_PSP_high  IPR1bits.PSPIP=1
#define set_CCP1_high  IPR1bits.CCP2IP=1

#define set_AD_low  IPR1bits.ADIP=0
#define set_RX_low  IPR1bits.RCIP=0
#define set_TX_low  IPR1bits.TXIP=0
#define set_SSP_low  IPR1bits.SSPIP=0
#define set_TMR1_low  IPR1bits.TMR1IP=0
#define set_TMR2_low  IPR1bits.TMR2IP=0
#define set_PSP_low  IPR1bits.PSPIP=0
#define set_CCP1_low  IPR1bits.CCP2IP=0


#define set_CCP2_high  IPR2bits.CCP2IP=1
#define set_TMR3_high  IPR2bits.TMR3IP=1
#define set_CM_high    IPR2bits.CMIP=1
#define set_EE_high    IPR2bits.EEIP=1
#define set_BC_high    IPR2bits.BCIP=1
#define set_OSCF_high    IPR2bits.OSCFIP=1
#define set_HLVD_high    IPR2bits.HLVDIP=1


#define set_CCP2_low  IPR2bits.CCP2IP=0
#define set_TMR3_low  IPR2bits.TMR3IP=0
#define set_CM_low    IPR2bits.CMIP=0
#define set_EE_low    IPR2bits.EEIP=0
#define set_BC_low    IPR2bits.BCIP=0
#define set_OSCF_low    IPR2bits.OSCFIP=0
#define set_HLVD_low    IPR2bits.HLVDIP=0
