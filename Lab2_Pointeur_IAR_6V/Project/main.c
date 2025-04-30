/* Includes ------------------------------------------------------------------*/
 #include "stm32f4xx.h"
/**
  ******************************************************************************
  * @file    Lab pointer/main.c 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    19-06-2019
  *****************************************************************************/
int Var1 = 0x11223344;
short Var2 = 0x5566;
char Var3 = 0x77;
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  
  int *pVar1;
  short int *pVar2;
  char *pVar3;

  pVar1 = &Var1;
  pVar2 = &Var2;
  pVar3 = &Var3;
  
  *pVar3 = *pVar1 + *pVar2;
  pVar3--;
  pVar2--;
  pVar1++;
  
  while (1)
  {}
}


/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/
