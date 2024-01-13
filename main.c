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

#include "lib_ili9341.h"
#include "mcc_generated_files/mcc.h"
/*
                         Main application
 */

uint16_t convertedValue;
char string[50] = "";

volatile bool SistemaControloLigado = false;
volatile bool BombaLigada = false;

volatile uint16_t nivel_referencia = 0;
volatile uint16_t nivel_referencia_percentagem = 0;
volatile uint16_t nivel_real = 0;
volatile uint16_t nivel_real_percentagem = 0;
volatile uint16_t erro_nivel = 0;

uint8_t rxData;
uint8_t menu = '0';
int temperatura = 18;
unsigned char cnt_char = 0;
unsigned char s[4];
unsigned char carater_recebido = 1;

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
    nivel_referencia = ADC_GetConversionResult();
    nivel_referencia_percentagem = (float)(nivel_referencia * 100.0) / 1023.0;
}

/**
 * Funcao que e chamada quando o timer 0 termina a contagem (25ms)
 */
void TMR0_MyInterruptHandler(void) {
    ADC_SelectChannel(channel_AN0);
    ADC_StartConversion();
    nivel_real = (uint16_t)CheckSensores();  // Verifica o estado dos sensores
    nivel_real_percentagem = (nivel_real * 100) / 10;
}

void TMR1_MyInterruptHandler(void) {
    // liga led laranja se o sistema de controlo estiver ligado com uma frequencia de 2Hz
    if (SistemaControloLigado) {
        IO_RB4_LED_ORANGE_Toggle();
    }
}

void TMR6_MyInterruptHandler(void) {
    IO_RC0_Led_HeartBeat_Toggle(); //heartbeat LED
}

//________________________________________________
void CheckUSART(void);
void ShowMenuInTerminal(void);
int CheckSensores(void);
void Draw_Welcome_Screen(void);
void Draw_Interface_Screen(void);

void main(void) {
    SYSTEM_Initialize();

    // inicia a comunicacao SPI com o LCD
    SPI2_Open(SPI2_DEFAULT);
    // Inicializa o LCD grafico
    lcd_init();
    // resolucao do LCD 320x240 (x = 0 a 319, y = 0 a 239)
    Draw_Welcome_Screen();

    INTERRUPT_GlobalInterruptHighEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    INTERRUPT_PeripheralInterruptEnable();

    INT0_SetInterruptHandler(INT0_MyInterruptHandler);
    ADC_SetInterruptHandler(ADC_MyInterruptHandler);
    TMR0_SetInterruptHandler(TMR0_MyInterruptHandler);
    TMR0_StartTimer();

    TMR1_SetInterruptHandler(TMR1_MyInterruptHandler);
    TMR1_StartTimer();

    TMR6_SetInterruptHandler(TMR6_MyInterruptHandler);
    TMR6_StartTimer();

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
        //fazer so a cada 3 loops
        static int i=0;
        if(i==3){
            Draw_Interface_Screen();
            i=0;
        }else{
            i++;
        }
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
            printf("\r\nPrima 0 para voltar ao Menu Principall");
            printf("\r\nOpcao: ");
            BombaLigada = false;
            menu = '0';
            break;
        case '2':  // Ativar comtrolo do nivel de agua
            EUSART1_Write(12);
            // TODO - Ativar controlo do nivel de agua
            printf("\r\nControlo do nivel de agua ativado!");
            SistemaControloLigado = true;
            printf("\r\n\nPrima 0 para voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        case '3':  // Visualizar a percentagem do nivel de agua
            EUSART1_Write(12);
            // TODO - Visualizar a percentagem do nivel de agua
            printf("\r\nPercentagem do nivel de agua: %hu", nivel_real_percentagem);
            printf("\r\nbits: %d", nivel_real);
            printf("\r\n\nPrima 0 para voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        case '4':  // Visualizar o nivel de referencia
            EUSART1_Write(12);
            // TODO - Visualizar o nivel de referencia
            printf("\r\n\nPrima 0 para voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        case '5':  // Programar novo valor de referencia
            EUSART1_Write(12);
            // TODO - Programar novo valor de referencia
            printf("\r\n\nPrima 0 para voltar ao Menu Principal");
            printf("\r\nOpcao: ");
            menu = '0';
            break;
        default:  // Opcao Invalida
            EUSART1_Write(12);
            printf("\r\nOpcao Invalida!");
            printf("\r\nPrima 0 para voltar ao Menu Principal");
            menu = '0';
            break;
    }
}

void CheckUSART() {
    if (EUSART1_is_rx_ready()) {
        rxData = EUSART1_Read();  // Funcao que le caracter da EUSART
        EUSART1_Write(rxData);    // Mostra caracter recebido devolvendo-o a EUART

        if ((rxData >= 48 && rxData <= 57) || rxData == 13) {
            carater_recebido = 1;  // Indica caracter aceite
            menu = rxData;         // O caracter será usado para o switch case
        } else {
            carater_recebido = 0;  // Caso contrario nao aceita o caracter e...
            menu = '0';            // ...volta a mostrar o menu principal opcao 0
        }
    }
}

int CheckSensores() {
    int getValueFuncs[10];                     // array dos sensores de nivel de agua
    getValueFuncs[0] = IO_RD7_N01_GetValue();  // sensor 1 PORTDbits.RD7
    getValueFuncs[1] = IO_RD6_N02_GetValue();  // sensor 2 PORTDbits.RD6
    getValueFuncs[2] = IO_RD5_N03_GetValue();  // sensor 3 PORTDbits.RD5
    getValueFuncs[3] = IO_RD3_N04_GetValue();  // sensor 4 PORTDbits.RD3
    getValueFuncs[4] = IO_RD2_N05_GetValue();  // sensor 5 PORTDbits.RD2
    getValueFuncs[5] = IO_RC5_N06_GetValue();  // sensor 6 PORTCbits.RC5
    getValueFuncs[6] = IO_RC4_N07_GetValue();  // sensor 7 PORTCbits.RC4
    getValueFuncs[7] = IO_RC3_N08_GetValue();  // sensor 8 PORTCbits.RC3
    getValueFuncs[8] = IO_RC2_N09_GetValue();  // sensor 9 PORTCbits.RC2
    getValueFuncs[9] = IO_RC1_N10_GetValue();  // sensor 10 PORTCbits.RC1
    int i;
    for (i = 0; i < 10; i++) {
        if (getValueFuncs[i] == 0) {
            return i + 1;
        }
    }
    return 0;
}

void Draw_Welcome_Screen() {
    lcd_draw_line(9, 210, 310, 210, ILI9341_WHITE);
    lcd_draw_string(40, 215, "ENGENHARIA ELETROTECNICA", BLACK, WHITE);
    snprintf(string, sizeof(string), "MICROPROCESSADORES");
    lcd_draw_string(60, 190, string, WHITE, BLACK);
    snprintf(string, sizeof(string), "2023 / 2024");
    lcd_draw_string(120, 165, string, WHITE, BLACK);
    snprintf(string, sizeof(string), "SISTEMA PARA CONTROLO");
    lcd_draw_string(20, 140, string, ILI9341_ORANGE, BLACK);
    snprintf(string, sizeof(string), "DO NIVEL DE AGUA");
    lcd_draw_string(20, 120, string, ILI9341_ORANGE, BLACK);
    snprintf(string, sizeof(string), "Autores: Pedro Ferreira");
    lcd_draw_string(20, 95, string, YELLOW, BLACK);
    snprintf(string, sizeof(string), "Bernardo Santos");
    lcd_draw_string(90, 75, string, YELLOW, BLACK);

    snprintf(string, sizeof(string), "Nivel de agua:");
    lcd_draw_string(20, 20, string, WHITE, BLACK);
    snprintf(string, sizeof(string), "Nivel de referencia:");
    lcd_draw_string(20, 40, string, WHITE, BLACK);
}

void Draw_Interface_Screen() {

    // barra branca de fundo
    lcd_fill_rect(275, 10, 295, 190, WHITE);

    // barra azul de agua
    uint16_t barra_agua = (nivel_real_percentagem * 180) / 100;
    if (barra_agua >= 180) {
        barra_agua = 180;
    } else if (barra_agua <= 0) {
        barra_agua = 11;
    }
    lcd_fill_rect(276, 11, 294, barra_agua, BLUE);

    // barra vermelha de referencia
    uint16_t barra_referencia = (nivel_referencia_percentagem * 180) / 100;

    if (barra_referencia >= 180) {
        barra_referencia = 180;
    } else if (barra_referencia <= 0) {
        barra_referencia = 11;
    }
    lcd_fill_rect(276, barra_referencia, 294, barra_referencia + 2, RED);

    // Display the percentages
    snprintf(string, sizeof(string), "%d%%", nivel_referencia_percentagem);
    lcd_draw_string(180, 40, string, WHITE, BLACK);
    snprintf(string, sizeof(string), "%d%%", nivel_real_percentagem);
    lcd_draw_string(140, 20, string, WHITE, BLACK);
}

// TODO - o valor de referencia do nivel de agua do tanque podera ser definido pelo utilizador de duas dforams (terminal ou potenciometro)
// TODO - timer para comparar o nivel de agua real com o de referencia e ligar ou desligar a bomba de agua
// TODO - timer para os sensores de nivel de agua e devover 0-100% de agua no tanque com resolucao de 10% mesma frequancia que o timer anterior
// TODO - nivel logico 0 quando o sensor esta em contacto com a agua e nivel logico 1 quando nao esta em contacto com a agua
// TODO - ligar ou desligar a bomba de agua com um gpio
// TODO - Indicador de sistema ligado: desligado quando o sistema de controlo estiver desligado, ativo com uma periodicidade de 2 Hz quando o sistema de controlo estiver ativo
// TODO - Indicador de sistema desligado: desligado quando o sistema de controlo estiver ativo, ligado (estaticamente) se o sistema estiver parado;
// TODO - Indicador de bomba de água em atuação: ligado enquanto o motor da bomba de água for ativo
// TODO - Buzzer para qunado o reservatorio estiver cheio
// TODO - Display LCD para mostrar o nivel de agua em percentagem e o nivel de referencia em percentagem (a cada ciclo do timer da malha fechada)
// TODO - ADC com timer para ler o valor do potenciometro
// TODO - Botao de emergencia para desligar a bomba de agua e o sistema de controlo
/*
Esta interface deverá permitir ao utilizador as seguintes operações:
• Desligar a bomba de água do reservatório;
• Ligar o sistema de controlo do nível de água do reservatório através de um dos
mecanismos de existentes, apresentando as opções:
o Potenciómetro
o Interface série
• Visualizar o valor atual da percentagem de nível de água no reservatório;
• Visualizar o valor atual programado para o nível de água de referência;
• Programar um novo valor de percentagem de referência do nível de água (qualquer
valor inteiro entre 0% e 100%). Esta opção deverá estar disponível apenas quando o
controlo está ligado no modo interface série;
*/