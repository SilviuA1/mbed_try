#include "TFC.h"


//set I/O for H-BRIDGE enables, switches and LEDs
void TFC_InitGPIO()
{
	//enable Clocks to all ports
	
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;

}
