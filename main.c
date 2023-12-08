/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC18F46K22
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
uint16_t convertedValue;
uint16_t nivel_agua = 0; // Nivel de agua em percentagem

//______________INTERRUPTS________________________
void INT0_MyInterruptHandler(void) {
    IO_RB3_LED_RED_Toggle();
    IO_RB4_LED_ORANGE_Toggle();
    printf("ola\r\n");

    EXT_INT0_InterruptFlagClear();
}

void ADC_MyInterruptHandler(void) {
    ADC_SelectChannel(channel_AN0);
    convertedValue = ADC_GetConversionResult();
    nivel_agua = (long) convertedValue * 100 / 1023;
}

void TMR0_MyInterruptHandler(void) {
    ADC_SelectChannel(channel_AN0);
    ADC_StartConversion();
}
//________________________________________________
void CheckUSART(void);
void ShowMenuInTerminal(void);

uint8_t rxData;
int temperatura = 18;
char menu = '0';
unsigned char cnt_char = 0;
unsigned char s[4];
unsigned char carater_recebido = 1;
unsigned char intro_valor = 0;

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    // INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    // INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    // INTERRUPT_PeripheralInterruptDisable();

    INT0_SetInterruptHandler(INT0_MyInterruptHandler);
    ADC_SetInterruptHandler(ADC_MyInterruptHandler);
    TMR0_SetInterruptHandler(TMR0_MyInterruptHandler);
    TMR0_StartTimer();

    printf("SETUP COMPLETED SUCCESSFULLY\r\n");

    while (1) {
        // printf("LOOPING\r\n");
        IO_RB5_LED_GREEN_SetHigh();

        if (carater_recebido) {
            ShowMenuInTerminal();
            carater_recebido = 0;
        }
        CheckUSART();

        // Add your application code
    }
}
/**
 End of File
*/

void ShowMenuInTerminal() {
    switch (menu) {
        case '0':               // Apresenta menu principal
            EUSART1_Write(12);  // Escreve na primeira linha do terminal
            printf("\r\nMENU PRINCIPAL");
            printf("\r\n1 - Desligar bomba de agua");
            printf("\r\n2 - Ativar comtrolo do nivel de agua");
            printf("\r\n3 - Visualizar a percentagem do nivel de agua");
            printf("\r\n4 - Visualizar o nivel de referencia");
            printf("\r\n5 - Programar novo valor de referencia");
            printf("\r\n0 - Voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = 0;
            break;
        case '1':  // Desligar bomba de agua
            EUSART1_Write(12);
            // TODO - Desligar bomba de agua
            printf("\r\nBomba de agua desligada");
            cnt_char = 0;  // Inicia a contagem de caracteres para compor esse valor
            menu = 0;
            break;
        case '2':  // Ativar comtrolo do nivel de agua
            EUSART1_Write(12);
            // TODO - Ativar controlo do nivel de agua
            printf("\r\nControlo do nivel de agua ativado");
            menu = 0;
            break;
        case '3':  // Visualizar a percentagem do nivel de agua
            EUSART1_Write(12);
            // TODO - Visualizar a percentagem do nivel de agua
            printf("\r\nPercentagem do nivel de agua: %d", nivel_agua);
            printf("\r\nbits: %d", convertedValue);
            menu = 0;
            break;
        case '4':  // Visualizar o nivel de referencia
            EUSART1_Write(12);
            // TODO - Visualizar o nivel de referencia
            menu = 0;
            break;
        case '5':  // Programar novo valor de referencia
            EUSART1_Write(12);
            // TODO - Programar novo valor de referencia
            menu = 0;
            break;
        default:  // Opcao Invalida
            EUSART1_Write(12);
            printf("\r\nOpcao Invalida");
            printf("\r\nPrima 0 para voltar ao Menu Principal");
            menu = 0;
            break;
    }
}

void CheckUSART() {
    if (EUSART1_is_rx_ready()) {
        rxData = EUSART1_Read();                               // Funcao que le caracter da EUSART
        EUSART1_Write(rxData);                                 // Mostra caracter recebido devolvendo-o ah EUSART
        if ((rxData >= '0' && rxData <= '9') || rxData == 13)  // Protecao / Se estiver enrtre 0 e 9 ou ENTER
        {
            carater_recebido = 1;  // Indica caracter aceite
            menu = rxData;         // O caracter ser]a usado para o switch case
        } else {
            carater_recebido = 0;  // Caso contrario nao aceita o caracter e...
            menu = '0';            // ...volta a mostrar o menu principal opcao 0
        }

        if (intro_valor == 1)  // Se estiver em modo de ler um valor para o programa e nao escolher um item do menu
        {
            menu = 1;  // Vai para o switch case 1 onde ira carregar os digitos lidos numa string
        }
    }
}