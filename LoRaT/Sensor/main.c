#include "HardwareProfile.h"
#include "Sx1262Proc.h"
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
#if !defined( USE_NO_TIMER )
    //RtcRecoverMcuStatus( );
#endif
    
    if (EXTI_GetITStatus(EXTI_IT) != RESET) {
      
        //clear the it status first, otherwise when do call RadioIrqProcess when it enableinterrupts() it will re-enter into the interrupt handler
        EXTI_ClearITPendingBit(EXTI_IT);
        HAL_GPIO_EXTI_Callback(EXTI_IT);
    }
}