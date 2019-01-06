#include "TFC.h"


volatile uint16_t  *LineScanImage0WorkingBuffer;
volatile uint16_t  *LineScanImage1WorkingBuffer;
volatile uint16_t  *LineScanImage0;
volatile uint16_t  *LineScanImage1;
volatile uint16_t  LineScanImage0Buffer[2][128];
volatile uint16_t  LineScanImage1Buffer[2][128];
volatile uint8_t  LineScanWorkingBuffer;

volatile uint8_t LineScanImageReady = 0;

void TFC_InitLineScanCamera()
{
    SIM->SCGC5 |=   SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK; //Make sure the clock is enabled for PORTE;
    //Set pins for CCD0
    PORTB->PCR[9] = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   //Enable GPIO on on the pin for the CLOCK Signal
    PORTB->PCR[8] = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   //Enable GPIO on on the pin for SI signal
    PORTC->PCR[2] = PORT_PCR_MUX(0); //Make sure AO signal goes to an analog input

    //Make sure the Clock and SI pins are outputs
    PTB->PDDR |= (1<<8);
    PTB->PDDR |= (1<<9);

    TAOS_CLK_LOW;
    TAOS_SI_LOW;

    LineScanWorkingBuffer = 0;

    LineScanImage0WorkingBuffer = &LineScanImage0Buffer[LineScanWorkingBuffer][0];
    LineScanImage1WorkingBuffer = &LineScanImage1Buffer[LineScanWorkingBuffer][0];

    LineScanImage0 = &LineScanImage0Buffer[1][0];
    LineScanImage1 = &LineScanImage1Buffer[1][0];
}


void TFC_SetLineScanExposureTime(uint32_t  TimeIn_uS)
{
		float t;
		
		//Figure out how many Pit ticks we need for for the exposure time
		t = (TimeIn_uS /1000000.0) * (float)(BOARD_BOOTCLOCKRUN_CORE_CLOCK/2);
		PIT->CHANNEL[0].LDVAL = (uint32_t)t;
	
}
