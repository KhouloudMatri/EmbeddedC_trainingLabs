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
#define VAR1 0x10
const int VAR2 = 0x20;
int Var3 = 0x30;
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  
  static int i = 6;
  
  int var4 = 4;
  int var5 = 5;
  int var6 = 6;
  int var7 = 7;
  int var8 = 8;
  int var9 = 9;
  int var10 = 10;
  char var11 = 127;
  int var12 = 250;
  char var13 = 13;
  int var14 = 14;
  
  float div = 0;
  
  int *p1; 
  int *p2;
  
  var11 = var4 + var12 +i ;
  
  div = (float)(VAR1 + VAR2 + Var3)/(var4+var5+var6+var7);

  p1 = (int *)malloc(4 * sizeof(int));
  *p1 = var7 + var8 + var13 ;
  free(p1);
  
  p2 = (int *)malloc(8 * sizeof(int));
  *p2 = var9 + var10 + var14; 
  
  while (1)
  {}
}


/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/
