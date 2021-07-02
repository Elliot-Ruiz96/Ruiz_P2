#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "board.h"
#include "clock_config.h"
#include "fsl_uart.h"
#include "pin_mux.h"

/*! @brief Ring buffer size (Unit: Byte). */
#define RING_BUFFER_SIZE 2

void UART_Config(void);
void UART_RX_TX_IRQHandler(void);

void Send_Data(void);
void Set_Data();
void Set_RxIndex(uint16_t);
void Set_TxIndex(uint16_t);

uint8_t Get_Data();
uint8_t Get_RxIndex();
uint16_t Get_TxIndex();

#endif /* UART_H_ */
