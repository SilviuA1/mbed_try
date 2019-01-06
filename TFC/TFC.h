/*
 * TFC.h
 *
 *  Created on: Apr 13, 2012
 *      Author: emh203
 */

#ifndef TFC_H_
#define TFC_H_
#include "MKL25Z4.h"
#include"fsl_adc16.h"
#include "fsl_common.h"
#include "clock_config.h"
#include "fsl_clock.h"

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
//#include "Derivative.h"
#include "TFC_Config.h"
//#include "TFC_Types.h"
//#include "TFC_arm_cm0.h"
#include "TFC_ARM_SysTick.h"
#include "TFC_BoardSupport.h"
//#include "TFC_CrystalClock.h"
#include "TFC_Servo.h"
#include "TFC_Motor.h"
#include "TFC_ADC.h"
#include "TFC_LineScanCamera.h"
//#include "TFC_Queue.h"
//#include "TFC_UART.h"
//#include "TFC_Terminal.h"

void TFC_Task();
void TFC_Init();

#endif /* TFC_H_ */
