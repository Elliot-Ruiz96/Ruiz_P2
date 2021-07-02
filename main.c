#include <string.h>

#include "Implementacion.h"
#include "I2C.h"
#include "PIT.h"
#include "Push_Buttons.h"
#include "RGB.h"

uint8_t g_Button2 = 0;
uint8_t g_Button3 = 0;

void PORTA_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOA, 1U << PIN4);
    g_Button2 = true;
    SDK_ISR_EXIT_BARRIER;
}

void PORTC_IRQHandler(void){
    GPIO_PortClearInterruptFlags(GPIOC, 1U << PIN6);
    g_Button3 = true;
    SDK_ISR_EXIT_BARRIER;
}

uint8_t Msg1[] =
		"\n Menu: \n 1. Configurar hora: \n 2. Configurar fecha: \n 3. Leer fecha: \n 4. Leer hora:";

int main(void) {
	PIT_Config();
	LED_Config();
	Buttons_Config();
	UART_Config();
	I2C_Init();
	UART_WriteBlocking(UART0, Msg1, sizeof(Msg1) / sizeof(Msg1[0]));
	while(1){
		Program_Init();
	}
    return 0;
}
