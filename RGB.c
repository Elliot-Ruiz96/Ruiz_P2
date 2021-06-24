#include "RGB.h"

void LED_Config(){
	gpio_pin_config_t led_config = {
	        kGPIO_DigitalOutput,
	        1,
	    };
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortE);
	PORT_SetPinMux(PORTB, PIN21, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, PIN22, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, PIN26, kPORT_MuxAsGpio);
	GPIO_PinInit(GPIOB, PIN22, &led_config);
	GPIO_PinInit(GPIOB, PIN21, &led_config);
	GPIO_PinInit(GPIOE, PIN26, &led_config);
}
void RED_RGB(){
	OFF_RGB();
	GPIO_PortClear(GPIOB, 1u << PIN22);
}
void GREEN_RGB(){
	OFF_RGB();
	GPIO_PortClear(GPIOE, 1u << PIN26);
}
void BLUE_RGB(){
	OFF_RGB();
	GPIO_PortClear(GPIOB, 1u << PIN21);
}
void PURPLE_RGB(){
	OFF_RGB();
	GPIO_PortClear(GPIOB, 1u << PIN21);
	GPIO_PortClear(GPIOB, 1u << PIN22);
}
void YELLOW_RGB(){
	OFF_RGB();
	GPIO_PortClear(GPIOB, 1u << PIN22);
	GPIO_PortClear(GPIOE, 1u << PIN26);
}
void LIGHTBLUE_RGB(){
	OFF_RGB();
	GPIO_PortClear(GPIOE, 1u << PIN26);
	GPIO_PortClear(GPIOB, 1u << PIN21);
}
void WHITE_RGB(){
	OFF_RGB();
	GPIO_PortClear(GPIOB, 1u << PIN21);
	GPIO_PortClear(GPIOB, 1u << PIN22);
	GPIO_PortClear(GPIOE, 1u << PIN26);
}
void OFF_RGB(){
	GPIO_PortSet(GPIOB, 1u << PIN21);
	GPIO_PortSet(GPIOB, 1u << PIN22);
	GPIO_PortSet(GPIOE, 1u << PIN26);
}
