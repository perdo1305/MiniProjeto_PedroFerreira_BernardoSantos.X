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

// Pedro Ferreira N2222035
// Bernardo Santos N2222033

#include "mcc_generated_files/mcc.h"
#include "lib_ili9341.h"
/*
                         Main application
 */
uint16_t convertedValue;
uint16_t nivel_agua = 0;  // Nivel de agua em percentagem
char string[50] = "";
volatile bool SistemaControloLigado = false;
volatile bool BombaLigada = false;
volatile uint16_t nivel_referencia = 0;

//______________INTERRUPTS________________________
void INT0_MyInterruptHandler(void) {
    // se o botao de emergencia for pressionado desliga o sistema de controlo
    BombaLigada = false;
    SistemaControloLigado = false;

    EXT_INT0_InterruptFlagClear();
}

/**
 * Funcao que e chamada quando o ADC termina a conversao
 */
void ADC_MyInterruptHandler(void) {
    ADC_SelectChannel(channel_AN0);
    convertedValue = ADC_GetConversionResult();
    nivel_agua = nivel_agua = (uint32_t)convertedValue * 100 / 1023;
}

/**
 * Funcao que e chamada quando o timer 0 termina a contagem (25ms)
 */
void TMR0_MyInterruptHandler(void) {
    ADC_SelectChannel(channel_AN0);
    ADC_StartConversion();
}

void TMR1_MyInterruptHandler(void) {
    // liga led laranja se o sistema de controlo estiver ligado com uma frequencia de 2Hz
    if (SistemaControloLigado) {
        IO_RB4_LED_ORANGE_Toggle();
    }
}

//________________________________________________
void CheckUSART(void);
void ShowMenuInTerminal(void);

uint8_t rxData;
uint8_t menu = '0';
int temperatura = 18;
unsigned char cnt_char = 0;
unsigned char s[4];
unsigned char carater_recebido = 1;
unsigned char intro_valor = 0;

void main(void) {
    SYSTEM_Initialize();

     SPI2_Open(SPI2_DEFAULT);
    // Inicializa o LCD grafico    
    lcd_init();
    
    
    lcd_draw_string(82, 220, "ENGENHARIA ELETROTECNICA", FUCHSIA, BLACK);
    snprintf(string, sizeof (string), "MICROPROCESSADORES");
    lcd_draw_string(85, 190, string, LIME, BLACK);
    snprintf(string, sizeof (string), "2022 / 23");
    lcd_draw_string(120, 165, string, ILI9341_PINK, BLACK);
    snprintf(string, sizeof (string), "SISTEMA PARA CONTROLO DE UM");
    lcd_draw_string(20, 140, string, RED, BLACK);
    snprintf(string, sizeof (string), "MOTOR EM MALHA ABERTA");
    lcd_draw_string(40, 120, string, RED, BLACK);
    snprintf(string, sizeof (string), "Autores: Pedro Ferreira");
    lcd_draw_string(20, 95, string, YELLOW, BLACK);
    snprintf(string, sizeof (string), "Bernardo Santos");
    lcd_draw_string(90, 75, string, YELLOW, BLACK);    
    
    INTERRUPT_GlobalInterruptHighEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    INTERRUPT_PeripheralInterruptEnable();

    INT0_SetInterruptHandler(INT0_MyInterruptHandler);
    ADC_SetInterruptHandler(ADC_MyInterruptHandler);
    TMR0_SetInterruptHandler(TMR0_MyInterruptHandler);
    TMR0_StartTimer();

    TMR1_SetInterruptHandler(TMR1_MyInterruptHandler);
    TMR1_StartTimer();

    printf("SETUP COMPLETED SUCCESSFULLY\r\n");
    SistemaControloLigado = true;

    while (1) {
        // Sistema de controlo desligado, desliga o timer e acende o led vermelho
        if (!SistemaControloLigado) {
            TMR1_StopTimer();
            IO_RB4_LED_ORANGE_SetLow();
            IO_RB3_LED_RED_SetHigh();
        } else {
            TMR1_StartTimer();
            IO_RB3_LED_RED_SetLow();
        }

        // se a bomba estiver ligada acende o led verde
        if (BombaLigada) {
            IO_RB5_LED_GREEN_SetHigh();
        } else {
            IO_RB5_LED_GREEN_SetLow();
        }

        if (carater_recebido) {
            ShowMenuInTerminal();
            carater_recebido = 0;
        }
        CheckUSART();
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
            menu = '0';
            break;
        case '1':  // Desligar bomba de agua
            EUSART1_Write(12);
            // TODO - Desligar bomba de agua
            printf("\r\nBomba de agua desligada");
            printf("\r\n0 - Voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            BombaLigada = false;
            menu = '0';
            break;
        case '2':  // Ativar comtrolo do nivel de agua
            EUSART1_Write(12);
            // TODO - Ativar controlo do nivel de agua
            printf("\r\nControlo do nivel de agua ativado!");
            SistemaControloLigado = true;
            printf("\r\n0 - Voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        case '3':  // Visualizar a percentagem do nivel de agua
            EUSART1_Write(12);
            // TODO - Visualizar a percentagem do nivel de agua
            printf("\r\nPercentagem do nivel de agua: %d", nivel_agua);
            printf("\r\nbits: %d", convertedValue);
            printf("\r\n0 - Voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        case '4':  // Visualizar o nivel de referencia
            EUSART1_Write(12);
            // TODO - Visualizar o nivel de referencia
            printf("\r\n0 - Voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        case '5':  // Programar novo valor de referencia
            EUSART1_Write(12);
            // TODO - Programar novo valor de referencia
            printf("\r\n0 - Voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        default:  // Opcao Invalida
            EUSART1_Write(12);
            printf("\r\nOpcao Invalida");
            printf("\r\nPrima 0 para voltar ao Menu Principal");
            menu = '0';
            break;
    }
}

void CheckUSART() {
    if (EUSART1_is_rx_ready()) {
        rxData = EUSART1_Read();  // Funcao que le caracter da EUSART
        EUSART1_Write(rxData);    // Mostra caracter recebido devolvendo-o ah EUSART

        switch (rxData) {
            case '0' ... '9':
            case 13:
                carater_recebido = 1;  // Indica caracter aceite
                menu = rxData;         // O caracter ser]a usado para o switch case
                break;
            default:
                carater_recebido = 0;  // Caso contrario nao aceita o caracter e...
                menu = '0';            // ...volta a mostrar o menu principal opcao 0
                break;
        }

        if (intro_valor == 1) {  // Se estiver em modo de ler um valor para o programa e nao escolher um item do menu
            menu = 1;            // Vai para o switch case 1 onde ira carregar os digitos lidos numa string
        }
    }
}