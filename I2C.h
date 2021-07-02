#ifndef I2C_H_
#define I2C_H_

#include <stdio.h>
#include <string.h>
#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "fsl_i2c.h"
#include "board.h"
#include "clock_config.h"
#include "pin_mux.h"

/* I2C source clock */
#define I2C_BAUDRATE               100000U
#define I2C_DATA_LENGTH            3U
#define I2C_MASTER_SLAVE_ADDR      0x68U
#define WAIT_TIME                  10U

void I2C_Init(void);
void Receive_Data(void);
void Transfer_Data(void);

#endif /* I2C_H_ */
