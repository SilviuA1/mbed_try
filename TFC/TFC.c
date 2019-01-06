#include "TFC.h"


void TFC_Init()
{
	TFC_InitSysTick();
	TFC_InitGPIO();
	TFC_InitServos();
	TFC_InitMotorPWM();
    TFC_InitADCs();
    TFC_InitLineScanCamera();
	TFC_SetMotorPWM(0,0);
}

