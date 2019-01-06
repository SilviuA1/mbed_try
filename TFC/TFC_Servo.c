#include "TFC.h"


#define FTM1_CLK_PRESCALE                                                            6// Prescale Selector value - see comments in Status Control (SC) section for more details
#define SERVO_DEFAULT_PERIOD                                                   (float)(.020)   // Desired Frequency of PWM Signal - Here 50Hz => 20ms period
// use these to dial in servo steering to your particular servo
#define SERVO_MIN_PULSE_WIDTH_DEFAULT                                          (float)0.0004 // The number here should be be *pulse width* in seconds to move servo to its right limit
#define SERVO_MAX_PULSE_WIDTH_DEFAULT                                          (float)0.0008  // The number here should be be *pulse width* in seconds to move servo to its left limit

float _ServoDutyCycleMin;
float _ServoDutyCycleMax;
float _ServoPeriod;

volatile uint16_t QueuedServo0Val;
volatile uint16_t QueuedServo1Val;

volatile unsigned char ServoTicker;

/**********************************************************************************************/

void TPM1_IRQHandler()
{
    //Clear the overflow mask if set.   According to the reference manual, we clear by writing a logic one!
    if(TPM1->SC & TPM_SC_TOF_MASK)
        TPM1->SC |= TPM_SC_TOF_MASK;

    //Dump the queued values to the timer channels
    TPM1->CONTROLS[0].CnV = QueuedServo0Val;
    TPM1->CONTROLS[1].CnV = QueuedServo1Val;

    //Flag that a new cervo cycle will start
    if (ServoTicker < 0xffffffff)//if servo tick less than max value, count up...
        ServoTicker++;

}


void TFC_InitServos()
{

    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;

    _ServoPeriod = SERVO_DEFAULT_PERIOD;
    _ServoDutyCycleMin = SERVO_MIN_PULSE_WIDTH_DEFAULT/SERVO_DEFAULT_PERIOD;
    _ServoDutyCycleMax = SERVO_MAX_PULSE_WIDTH_DEFAULT/SERVO_DEFAULT_PERIOD;

    //Clock Setup for the TPM requires a couple steps.
    SIM->SCGC6 &= ~SIM_SCGC6_TPM1_MASK;
    //1st,  set the clock mux
    //See Page 124 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
    SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK;// We Want MCGPLLCLK/2 (See Page 196 of the KL25 Sub-Family Reference Manual, Rev. 3, September 2012)
    SIM->SOPT2 &= ~(SIM_SOPT2_TPMSRC_MASK);
    SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);

    //Enable the Clock to the FTM0 Module
    //See Page 207 of f the KL25 Sub-Family Reference Manual, Rev. 3, September 2012
    SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK;

    //The TPM Module has Clock.  Now set up the peripheral

    //Blow away the control registers to ensure that the counter is not running
    TPM1->SC = 0;
    TPM1->CONF = 0;

    //While the counter is disabled we can setup the prescaler

    TPM1->SC = TPM_SC_PS(FTM1_CLK_PRESCALE);
    TPM1->SC |= TPM_SC_TOIE_MASK; //Enable Interrupts for the Timer Overflow

    //Setup the mod register to get the correct PWM Period

    TPM1->MOD = (CLOCK_GetCoreSysClkFreq()/(1<<(FTM1_CLK_PRESCALE))) * _ServoPeriod;
    //Setup Channels 0 and 1

    TPM1->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;
    TPM1->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;


    //Set the Default duty cycle to servo neutral
    TFC_SetServo(0, 0.0);
    TFC_SetServo(1, 0.0);

    //Enable the TPM COunter
    TPM1->SC |= TPM_SC_CMOD(1);

    //Enable TPM1 IRQ on the NVIC

    //NVIC_SetVector(TPM1_IRQn,(uint32_t)TPM1_Handler);
    NVIC_EnableIRQ(TPM1_IRQn);

    //Enable the FTM functions on the the port

    PORTA->PCR[12] = PORT_PCR_MUX(3);
    PORTA->PCR[13] = PORT_PCR_MUX(3);

}


void TFC_SetServoDutyCycle(uint8_t ServoNumber, float DutyCycle)
{
    switch(ServoNumber) {
        default:
        case 0:

            QueuedServo0Val = TPM1->MOD * DutyCycle;

            break;

        case 1:

            QueuedServo1Val = TPM1->MOD * DutyCycle;

            break;
    }
}

void TFC_SetServo(uint8_t ServoNumber, float Position)
{
    TFC_SetServoDutyCycle(ServoNumber ,
                          ((Position + 1.0)/2)    *   ((_ServoDutyCycleMax - _ServoDutyCycleMin))+_ServoDutyCycleMin) ;

}
