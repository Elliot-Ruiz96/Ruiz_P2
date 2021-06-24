#ifndef RGB_H_
#define RGB_H_

#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

#define PIN21       21u
#define PIN22       22u
#define PIN26		26u

void LED_Config();
void RED_RGB();
void GREEN_RGB();
void BLUE_RGB();
void PURPLE_RGB();
void YELLOW_RGB();
void LIGHTBLUE_RGB();
void WHITE_RGB();
void OFF_RGB();

#endif /* RGB_H_ */
