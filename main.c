#include "PIT.h"
#include "Push_Buttons.h"
#include "RGB.h"
#include "UART.h"

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
	Buttons_Config();
	LED_Config();
	PIT_Config();
	UART_Config();
	while(1){
	}
    return 0;
}
