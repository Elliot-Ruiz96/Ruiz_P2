#include "Push_Buttons.h"

void Buttons_Config(){
	gpio_pin_config_t sw_config = {
	        kGPIO_DigitalInput,
	        0,
	    };
	const port_pin_config_t sw_pin_config = {
	    kPORT_PullUp,
	    kPORT_FastSlewRate,
	    kPORT_PassiveFilterDisable,
	    kPORT_OpenDrainDisable,
	    kPORT_HighDriveStrength,
	    kPORT_MuxAsGpio,
	    kPORT_UnlockRegister
	  };
	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortC);
	PORT_SetPinConfig(PORTA, PIN4, &sw_pin_config);
	PORT_SetPinConfig(PORTC, PIN6, &sw_pin_config);
	GPIO_PinInit(GPIOA, PIN4, &sw_config);
	GPIO_PinInit(GPIOC, PIN6, &sw_config);
	PORT_SetPinInterruptConfig(PORTC, PIN6, kPORT_InterruptFallingEdge);
	PORT_SetPinInterruptConfig(PORTA, PIN4, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTC_IRQn);
	NVIC_SetPriority(PORTC_IRQn, 1);
	NVIC_EnableIRQ(PORTA_IRQn);
	NVIC_SetPriority(PORTA_IRQn, 1);
}
