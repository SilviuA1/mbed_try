#ifndef TFC_LINESCANCAMERA_H_
#define TFC_LINESCANCAMERA_H_


void TFC_InitLineScanCamera();
void TFC_LineScanImageCamera();

void TFC_SetLineScanExposureTime(uint32_t  TimeIn_uS);


#define TAOS_CLK_HIGH  GPIOB->PSOR = (1<<9)
#define TAOS_CLK_LOW   GPIOB->PCOR = (1<<9)
#define TAOS_SI_HIGH   GPIOB->PSOR = (1<<8)
#define TAOS_SI_LOW    GPIOB->PCOR = (1<<8)

extern volatile uint16_t  *LineScanImage0WorkingBuffer;
extern volatile uint16_t  *LineScanImage1WorkingBuffer;
extern volatile uint16_t  *LineScanImage0;
extern volatile uint16_t  *LineScanImage1;
extern volatile uint16_t  LineScanImage0Buffer[2][128];
extern volatile uint16_t  LineScanImage1Buffer[2][128];
extern volatile uint8_t  LineScanWorkingBuffer;
extern volatile uint8_t  LineScanImageReady;

#endif /* TFC_LINESCANCAMERA_H_ */
