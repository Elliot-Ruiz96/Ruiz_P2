#include "Implementacion.h"

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

void Program_Init(){
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
}
