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

// get/set IO_RB5_LED_GREEN aliases
#define IO_RB5_LED_GREEN_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LED_GREEN_LAT                  LATBbits.LATB5
#define IO_RB5_LED_GREEN_PORT                 PORTBbits.RB5
#define IO_RB5_LED_GREEN_WPU                  WPUBbits.WPUB5
#define IO_RB5_LED_GREEN_ANS                  ANSELBbits.ANSB5
#define IO_RB5_LED_GREEN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_LED_GREEN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_LED_GREEN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_LED_GREEN_GetValue()           PORTBbits.RB5
#define IO_RB5_LED_GREEN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_LED_GREEN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_LED_GREEN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_LED_GREEN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_LED_GREEN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_RB5_LED_GREEN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RC2_10 aliases
#define IO_RC2_10_TRIS                 TRISCbits.TRISC2
#define IO_RC2_10_LAT                  LATCbits.LATC2
#define IO_RC2_10_PORT                 PORTCbits.RC2
#define IO_RC2_10_ANS                  ANSELCbits.ANSC2
#define IO_RC2_10_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_10_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_10_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_10_GetValue()           PORTCbits.RC2
#define IO_RC2_10_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_10_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_10_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_10_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC3_9 aliases
#define IO_RC3_9_TRIS                 TRISCbits.TRISC3
#define IO_RC3_9_LAT                  LATCbits.LATC3
#define IO_RC3_9_PORT                 PORTCbits.RC3
#define IO_RC3_9_ANS                  ANSELCbits.ANSC3
#define IO_RC3_9_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_9_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_9_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_9_GetValue()           PORTCbits.RC3
#define IO_RC3_9_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_9_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_9_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_RC3_9_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

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

// get/set IO_RD0_8 aliases
#define IO_RD0_8_TRIS                 TRISDbits.TRISD0
#define IO_RD0_8_LAT                  LATDbits.LATD0
#define IO_RD0_8_PORT                 PORTDbits.RD0
#define IO_RD0_8_ANS                  ANSELDbits.ANSD0
#define IO_RD0_8_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_8_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_8_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_8_GetValue()           PORTDbits.RD0
#define IO_RD0_8_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_8_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_8_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define IO_RD0_8_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IO_RD1_7 aliases
#define IO_RD1_7_TRIS                 TRISDbits.TRISD1
#define IO_RD1_7_LAT                  LATDbits.LATD1
#define IO_RD1_7_PORT                 PORTDbits.RD1
#define IO_RD1_7_ANS                  ANSELDbits.ANSD1
#define IO_RD1_7_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_7_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_7_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_7_GetValue()           PORTDbits.RD1
#define IO_RD1_7_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_7_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_7_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define IO_RD1_7_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IO_RD2_6 aliases
#define IO_RD2_6_TRIS                 TRISDbits.TRISD2
#define IO_RD2_6_LAT                  LATDbits.LATD2
#define IO_RD2_6_PORT                 PORTDbits.RD2
#define IO_RD2_6_ANS                  ANSELDbits.ANSD2
#define IO_RD2_6_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_6_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_6_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_6_GetValue()           PORTDbits.RD2
#define IO_RD2_6_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_6_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_6_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_RD2_6_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IO_RD3_5 aliases
#define IO_RD3_5_TRIS                 TRISDbits.TRISD3
#define IO_RD3_5_LAT                  LATDbits.LATD3
#define IO_RD3_5_PORT                 PORTDbits.RD3
#define IO_RD3_5_ANS                  ANSELDbits.ANSD3
#define IO_RD3_5_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_5_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_5_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_5_GetValue()           PORTDbits.RD3
#define IO_RD3_5_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_5_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_5_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define IO_RD3_5_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set IO_RD4_4 aliases
#define IO_RD4_4_TRIS                 TRISDbits.TRISD4
#define IO_RD4_4_LAT                  LATDbits.LATD4
#define IO_RD4_4_PORT                 PORTDbits.RD4
#define IO_RD4_4_ANS                  ANSELDbits.ANSD4
#define IO_RD4_4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_RD4_4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_RD4_4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_RD4_4_GetValue()           PORTDbits.RD4
#define IO_RD4_4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_RD4_4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_RD4_4_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define IO_RD4_4_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set IO_RD5_3 aliases
#define IO_RD5_3_TRIS                 TRISDbits.TRISD5
#define IO_RD5_3_LAT                  LATDbits.LATD5
#define IO_RD5_3_PORT                 PORTDbits.RD5
#define IO_RD5_3_ANS                  ANSELDbits.ANSD5
#define IO_RD5_3_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_RD5_3_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_RD5_3_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_RD5_3_GetValue()           PORTDbits.RD5
#define IO_RD5_3_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_RD5_3_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_RD5_3_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define IO_RD5_3_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set IO_RD6_2 aliases
#define IO_RD6_2_TRIS                 TRISDbits.TRISD6
#define IO_RD6_2_LAT                  LATDbits.LATD6
#define IO_RD6_2_PORT                 PORTDbits.RD6
#define IO_RD6_2_ANS                  ANSELDbits.ANSD6
#define IO_RD6_2_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_RD6_2_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_RD6_2_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_RD6_2_GetValue()           PORTDbits.RD6
#define IO_RD6_2_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_RD6_2_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_RD6_2_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define IO_RD6_2_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set IO_RD7_1 aliases
#define IO_RD7_1_TRIS                 TRISDbits.TRISD7
#define IO_RD7_1_LAT                  LATDbits.LATD7
#define IO_RD7_1_PORT                 PORTDbits.RD7
#define IO_RD7_1_ANS                  ANSELDbits.ANSD7
#define IO_RD7_1_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_1_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_1_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_1_GetValue()           PORTDbits.RD7
#define IO_RD7_1_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_1_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_1_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define IO_RD7_1_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

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