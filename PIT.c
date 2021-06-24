#include "PIT.h"

volatile bool pitIsrFlag = false;

void PIT_Config(void){
    pit_config_t pitConfig;
    uint32_t freq = 0;
    freq = CLOCK_GetFreq(kCLOCK_BusClk);
    //Initialize
    PIT_Init(PIT, &pitConfig);
    PIT_GetDefaultConfig(&pitConfig);
    // Timer period
    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000000U, freq));
    //Start timer
    PIT_StartTimer(PIT, kPIT_Chnl_0);
    //NVIC
    EnableIRQ(PIT0_IRQn);
    PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
}

uint8_t PITflag_get_pit(void){
    return (pitIsrFlag);
}

void PIT0_IRQHandler(void){
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    pitIsrFlag = true;
    __DSB();
}

void PITflag_set_pit(void){
    pitIsrFlag = false;
}
