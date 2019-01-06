/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "TFC.h"
#include "pin_mux.h"
#include <stdlib.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */

int main(void)
{
    /* Init board hardware. */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    TFC_Init();

	uint32_t t,i=0;

	TFC_Init();
	int selection = 0;
	for(;;)
	{

	        PRINTF("Select component to test:\r\n0: Servo (SM1)\r\n1: Motors\r\n2: Camera (CCD1)\r\n");
	        SCANF("%d", &selection);
			switch(selection)
			{
			case 0:
				PRINTF("Testing Servo (SM1). Restart the board to stop.\r\n");
				float servoVal = -1.0;
                TFC_SetServo(0,servoVal);

                while(1)
                {
                	servoVal += 0.5;
                    if(servoVal>1) {
                    	servoVal = -1;
                    }
                    TFC_SetServo(0,servoVal);
                    TFC_Delay_mS(1000);
                }

				break;

			case 1 :
                PRINTF("Testing Motors. Restart the board to stop.\r\n");
                PRINTF("Enter value between -1 and 1. Format: +xx.xx (must include +/- sign)\r\n");

                float duty = 0;

                SCANF("%f", &duty);
                PRINTF("%+f", duty);
                PRINTF("\r\n");

                TFC_SetMotorPWM(duty,duty);
                while(1) {
                    PRINTF("Enter value between -1 and 1. Format: +xx.xx (must include +/- sign)\r\n");
                    SCANF("%f", &duty);
                    PRINTF("%+f", duty);
                    PRINTF("\r\n");
                    TFC_SetMotorPWM(duty,duty);
                }

				break;

			case 2 :

                PRINTF("Testing Camera. Restart the board to stop.\r\n");

				if(TFC_Ticker[0]>100 && LineScanImageReady==1)
					{
					 TFC_Ticker[0] = 0;
					 LineScanImageReady=0;
					 PRINTF("\r\n");
					 PRINTF("L:");

					 	if(t==0)
					 		t=3;
					 	else
					 		t--;

						 for(i=0;i<128;i++)
						 {
								 PRINTF("%d,",LineScanImage0[i]);
						 }

						 for(i=0;i<128;i++)
						 {
								 PRINTF("%d",LineScanImage1[i]);
								 if(i==127)
									 PRINTF("\r\n",LineScanImage1[i]);
								 else
									 PRINTF(",",LineScanImage1[i]);
						}

					}
				break;
			}
	}

	return 0;
}
