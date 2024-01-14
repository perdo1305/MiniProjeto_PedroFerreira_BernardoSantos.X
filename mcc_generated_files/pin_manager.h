/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC18F46K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_ANS                  ANSELAbits.ANSA0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()              PORTAbits.RA6
#define RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IO_RB3_LED_RED aliases
#define IO_RB3_LED_RED_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LED_RED_LAT                  LATBbits.LATB3
#define IO_RB3_LED_RED_PORT                 PORTBbits.RB3
#define IO_RB3_LED_RED_WPU                  WPUBbits.WPUB3
#define IO_RB3_LED_RED_ANS                  ANSELBbits.ANSB3
#define IO_RB3_LED_RED_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_LED_RED_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_LED_RED_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_LED_RED_GetValue()           PORTBbits.RB3
#define IO_RB3_LED_RED_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_LED_RED_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_LED_RED_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_LED_RED_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_LED_RED_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define IO_RB3_LED_RED_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set IO_RB4_LED_ORANGE aliases
#define IO_RB4_LED_ORANGE_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LED_ORANGE_LAT                  LATBbits.LATB4
#define IO_RB4_LED_ORANGE_PORT                 PORTBbits.RB4
#define IO_RB4_LED_ORANGE_WPU                  WPUBbits.WPUB4
#define IO_RB4_LED_ORANGE_ANS                  ANSELBbits.ANSB4
#define IO_RB4_LED_ORANGE_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_LED_ORANGE_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_LED_ORANGE_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_LED_ORANGE_GetValue()           PORTBbits.RB4
#define IO_RB4_LED_ORANGE_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_LED_ORANGE_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_LED_ORANGE_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_LED_ORANGE_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_LED_ORANGE_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define IO_RB4_LED_ORANGE_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IO_RB6_Led_HeartBeat aliases
#define IO_RB6_Led_HeartBeat_TRIS                 TRISBbits.TRISB6
#define IO_RB6_Led_HeartBeat_LAT                  LATBbits.LATB6
#define IO_RB6_Led_HeartBeat_PORT                 PORTBbits.RB6
#define IO_RB6_Led_HeartBeat_WPU                  WPUBbits.WPUB6
#define IO_RB6_Led_HeartBeat_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_Led_HeartBeat_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Led_HeartBeat_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_Led_HeartBeat_GetValue()           PORTBbits.RB6
#define IO_RB6_Led_HeartBeat_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_Led_HeartBeat_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_Led_HeartBeat_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_Led_HeartBeat_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set IO_RB7_Motor_Control aliases
#define IO_RB7_Motor_Control_TRIS                 TRISBbits.TRISB7
#define IO_RB7_Motor_Control_LAT                  LATBbits.LATB7
#define IO_RB7_Motor_Control_PORT                 PORTBbits.RB7
#define IO_RB7_Motor_Control_WPU                  WPUBbits.WPUB7
#define IO_RB7_Motor_Control_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_Motor_Control_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Motor_Control_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_Motor_Control_GetValue()           PORTBbits.RB7
#define IO_RB7_Motor_Control_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_Motor_Control_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_Motor_Control_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_Motor_Control_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set IO_RC0_N09 aliases
#define IO_RC0_N09_TRIS                 TRISCbits.TRISC0
#define IO_RC0_N09_LAT                  LATCbits.LATC0
#define IO_RC0_N09_PORT                 PORTCbits.RC0
#define IO_RC0_N09_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_N09_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_N09_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_N09_GetValue()           PORTCbits.RC0
#define IO_RC0_N09_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_N09_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set IO_RC1_N10 aliases
#define IO_RC1_N10_TRIS                 TRISCbits.TRISC1
#define IO_RC1_N10_LAT                  LATCbits.LATC1
#define IO_RC1_N10_PORT                 PORTCbits.RC1
#define IO_RC1_N10_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_N10_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_N10_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_N10_GetValue()           PORTCbits.RC1
#define IO_RC1_N10_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_N10_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set IO_RC2_Buzzer aliases
#define IO_RC2_Buzzer_TRIS                 TRISCbits.TRISC2
#define IO_RC2_Buzzer_LAT                  LATCbits.LATC2
#define IO_RC2_Buzzer_PORT                 PORTCbits.RC2
#define IO_RC2_Buzzer_ANS                  ANSELCbits.ANSC2
#define IO_RC2_Buzzer_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_Buzzer_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Buzzer_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_Buzzer_GetValue()           PORTCbits.RC2
#define IO_RC2_Buzzer_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_Buzzer_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_Buzzer_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_Buzzer_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC3_N08 aliases
#define IO_RC3_N08_TRIS                 TRISCbits.TRISC3
#define IO_RC3_N08_LAT                  LATCbits.LATC3
#define IO_RC3_N08_PORT                 PORTCbits.RC3
#define IO_RC3_N08_ANS                  ANSELCbits.ANSC3
#define IO_RC3_N08_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_N08_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_N08_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_N08_GetValue()           PORTCbits.RC3
#define IO_RC3_N08_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_N08_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_N08_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_RC3_N08_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_RC4_N07 aliases
#define IO_RC4_N07_TRIS                 TRISCbits.TRISC4
#define IO_RC4_N07_LAT                  LATCbits.LATC4
#define IO_RC4_N07_PORT                 PORTCbits.RC4
#define IO_RC4_N07_ANS                  ANSELCbits.ANSC4
#define IO_RC4_N07_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_N07_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_N07_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_N07_GetValue()           PORTCbits.RC4
#define IO_RC4_N07_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_N07_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_N07_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_RC4_N07_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_RC5_N06 aliases
#define IO_RC5_N06_TRIS                 TRISCbits.TRISC5
#define IO_RC5_N06_LAT                  LATCbits.LATC5
#define IO_RC5_N06_PORT                 PORTCbits.RC5
#define IO_RC5_N06_ANS                  ANSELCbits.ANSC5
#define IO_RC5_N06_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_N06_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_N06_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_N06_GetValue()           PORTCbits.RC5
#define IO_RC5_N06_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_N06_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_N06_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_N06_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_ANS                  ANSELDbits.ANSD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_ANS                  ANSELDbits.ANSD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IO_RD2_N05 aliases
#define IO_RD2_N05_TRIS                 TRISDbits.TRISD2
#define IO_RD2_N05_LAT                  LATDbits.LATD2
#define IO_RD2_N05_PORT                 PORTDbits.RD2
#define IO_RD2_N05_ANS                  ANSELDbits.ANSD2
#define IO_RD2_N05_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_N05_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_N05_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_N05_GetValue()           PORTDbits.RD2
#define IO_RD2_N05_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_N05_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_N05_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_RD2_N05_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IO_RD3_N04 aliases
#define IO_RD3_N04_TRIS                 TRISDbits.TRISD3
#define IO_RD3_N04_LAT                  LATDbits.LATD3
#define IO_RD3_N04_PORT                 PORTDbits.RD3
#define IO_RD3_N04_ANS                  ANSELDbits.ANSD3
#define IO_RD3_N04_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_N04_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_N04_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_N04_GetValue()           PORTDbits.RD3
#define IO_RD3_N04_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_N04_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_N04_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define IO_RD3_N04_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set IO_RD4 aliases
#define IO_RD4_TRIS                 TRISDbits.TRISD4
#define IO_RD4_LAT                  LATDbits.LATD4
#define IO_RD4_PORT                 PORTDbits.RD4
#define IO_RD4_ANS                  ANSELDbits.ANSD4
#define IO_RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_RD4_GetValue()           PORTDbits.RD4
#define IO_RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_RD4_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define IO_RD4_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set IO_RD5_N03 aliases
#define IO_RD5_N03_TRIS                 TRISDbits.TRISD5
#define IO_RD5_N03_LAT                  LATDbits.LATD5
#define IO_RD5_N03_PORT                 PORTDbits.RD5
#define IO_RD5_N03_ANS                  ANSELDbits.ANSD5
#define IO_RD5_N03_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_RD5_N03_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_RD5_N03_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_RD5_N03_GetValue()           PORTDbits.RD5
#define IO_RD5_N03_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_RD5_N03_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_RD5_N03_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define IO_RD5_N03_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set IO_RD6_N02 aliases
#define IO_RD6_N02_TRIS                 TRISDbits.TRISD6
#define IO_RD6_N02_LAT                  LATDbits.LATD6
#define IO_RD6_N02_PORT                 PORTDbits.RD6
#define IO_RD6_N02_ANS                  ANSELDbits.ANSD6
#define IO_RD6_N02_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_RD6_N02_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_RD6_N02_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_RD6_N02_GetValue()           PORTDbits.RD6
#define IO_RD6_N02_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_RD6_N02_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_RD6_N02_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define IO_RD6_N02_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set IO_RD7_N01 aliases
#define IO_RD7_N01_TRIS                 TRISDbits.TRISD7
#define IO_RD7_N01_LAT                  LATDbits.LATD7
#define IO_RD7_N01_PORT                 PORTDbits.RD7
#define IO_RD7_N01_ANS                  ANSELDbits.ANSD7
#define IO_RD7_N01_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_N01_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_N01_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_N01_GetValue()           PORTDbits.RD7
#define IO_RD7_N01_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_N01_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_N01_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define IO_RD7_N01_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set IO_RE0 aliases
#define IO_RE0_TRIS                 TRISEbits.TRISE0
#define IO_RE0_LAT                  LATEbits.LATE0
#define IO_RE0_PORT                 PORTEbits.RE0
#define IO_RE0_ANS                  ANSELEbits.ANSE0
#define IO_RE0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define IO_RE0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define IO_RE0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define IO_RE0_GetValue()           PORTEbits.RE0
#define IO_RE0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define IO_RE0_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define IO_RE0_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set IO_RE1 aliases
#define IO_RE1_TRIS                 TRISEbits.TRISE1
#define IO_RE1_LAT                  LATEbits.LATE1
#define IO_RE1_PORT                 PORTEbits.RE1
#define IO_RE1_ANS                  ANSELEbits.ANSE1
#define IO_RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define IO_RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define IO_RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define IO_RE1_GetValue()           PORTEbits.RE1
#define IO_RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define IO_RE1_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define IO_RE1_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set RE2 procedures
#define RE2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define RE2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define RE2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define RE2_GetValue()              PORTEbits.RE2
#define RE2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define RE2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define RE2_SetAnalogMode()         do { ANSELEbits.ANSE2 = 1; } while(0)
#define RE2_SetDigitalMode()        do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/