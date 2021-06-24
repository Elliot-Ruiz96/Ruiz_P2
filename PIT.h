#ifndef PIT_H_
#define PIT_H_

#include <stdint.h>
#include <stdio.h>
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "pin_mux.h"
#include "fsl_port.h"
#include "fsl_pit.h"
#include "board.h"
#include "clock_config.h"

void PIT_Config(void);

uint8_t PITflag_get_pit(void);
void PIT0_IRQHandler(void);
void PITflag_set_pit(void);


#endif /* PIT_H_ */
