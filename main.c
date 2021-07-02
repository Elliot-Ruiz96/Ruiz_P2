#include "Implementacion.h"

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
