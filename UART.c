#include "UART.h"

uint8_t Data;
uint8_t RingBuffer[RING_BUFFER_SIZE];
volatile uint16_t txIndex; /* Index of the data to send out. */
volatile uint16_t rxIndex; /* Index of the memory to save new arrived data. */

void UART_Config(void){
	uart_config_t config;
	BOARD_InitPins();
	BOARD_BootClockRUN();
	UART_GetDefaultConfig(&config);
	config.baudRate_Bps = 115200U;
	config.enableTx = true;
	config.enableRx = true;
	UART_Init(UART0, &config, CLOCK_GetFreq(kCLOCK_CoreSysClk));
	UART_EnableInterrupts(UART0, kUART_RxDataRegFullInterruptEnable | kUART_RxOverrunInterruptEnable);
	EnableIRQ(UART0_RX_TX_IRQn);
}

//ISR for UART
void UART_RX_TX_IRQHandler(void){
	 /* If new data arrived. */
	if ((kUART_RxDataRegFullFlag | kUART_RxOverrunFlag) & UART_GetStatusFlags(UART0)){
		Data = UART_ReadByte(UART0);
		/* If ring buffer is not full, add data to ring buffer. */
		if (((rxIndex + 1) % RING_BUFFER_SIZE) != txIndex){
			RingBuffer[rxIndex] = Data;
			rxIndex ++;
			rxIndex %= RING_BUFFER_SIZE;
		}
	}
	SDK_ISR_EXIT_BARRIER;
}

void Send_Data(void){
	/* Send data only when UART TX register is empty and ring buffer has data to send out. */
	while ((kUART_TxDataRegEmptyFlag & UART_GetStatusFlags(UART0)) && (rxIndex != txIndex))
	{
		UART_WriteByte(UART0, RingBuffer[txIndex]);
		Data = *(RingBuffer + txIndex);
		txIndex ++;
		txIndex %= RING_BUFFER_SIZE;
	}
}

void Set_Data(){
	Data = false;
}

void Set_RxIndex(uint16_t Dato){
	rxIndex = Dato;
}

void Set_TxIndex(uint16_t Dato){
	txIndex = Dato;
}

uint8_t Get_Data(){
	return Data;
}

uint8_t Get_RxIndex(){
	return rxIndex;
}

uint16_t Get_TxIndex(){
	return txIndex;
}
