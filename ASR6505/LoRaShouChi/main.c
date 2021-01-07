#include "HardwareProfile.h"
#include "radio.h"
#include "wfDefine.h"
void SystemInit(void);
int main( void )
{
	SystemInit();
// 	BoardInitMcu();
// 	BoardInitPeriph();
// 	Sx1262_Init();
	return 0;
}
void HAL_GPIO_EXTI_IRQHandler(EXTI_IT_TypeDef EXTI_IT)
{
	if (EXTI_GetITStatus(EXTI_IT) != RESET) 
	{
		//clear the it status first, otherwise when do call RadioIrqProcess when it enableinterrupts() it will re-enter into the interrupt handler
		EXTI_ClearITPendingBit(EXTI_IT);
		switch (EXTI_IT)
		{
		case EXTI_IT_Pin2://sx1262
			RadioIrqProcess();
			break;
		default:
			break;
		}
	}
}
