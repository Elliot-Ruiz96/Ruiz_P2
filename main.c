#include <string.h>

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
uint8_t Msg2[] =
		"\r\n Ingresa la hora (hh:mm:ss): \n";
uint8_t Msg3[] =
		"\r\n Ingresa la fecha (dd:mm:aa):\n";
uint8_t Msg4[] =
		"\r\n La hora es:\n";
uint8_t Msg5[] =
		"\r\n La fecha es:\n";

int main(void) {
	PIT_Config();
	LED_Config();
	Buttons_Config();
	UART_Config();
	I2C_Init();
	UART_WriteBlocking(UART0, Msg1, sizeof(Msg1) / sizeof(Msg1[0]));
	while(1){
		Send_Data();
		if(Get_Data() == '1'){
			if(Get_Gata() == 13){
				// Configuracion de hora
				printf("Enter key is pressed\n");
				UART_WriteBlocking(UART0, Msg2, sizeof(Msg2) / sizeof(Msg2[0]));
				set_data();
			}
		}
		if(Get_Data() == '2'){
			if(Get_Data() == 13){
				//Configuracion de fecha
				printf("Enter key is pressed\n");
				UART_WriteBlocking(UART0, Msg3, sizeof(Msg3) / sizeof(Msg3[0]));
				Set_Data();
			}
		}
		if(Get_Data() == '3'){
			if(Get_Data() == 13){
				//Mostrar fecha
				printf("Enter key is pressed\n");
				UART_WriteBlocking(UART0, Msg4, sizeof(Msg4) / sizeof(Msg4[0]));  // muestra la opcion de cambio de frecuencia
				Set_Data();
			}
		}

		if(Get_Data() == '4'){
			if(Get_Data() == 13){
				//Mostrar hora
				printf("Enter key is pressed\n");
				UART_WriteBlocking(UART0, Msg5, sizeof(Msg5) / sizeof(Msg5[0]));  // muestra la opcion de cambio de frecuencia
				Set_Data();
			}
		}
    return 0;
	}
}
