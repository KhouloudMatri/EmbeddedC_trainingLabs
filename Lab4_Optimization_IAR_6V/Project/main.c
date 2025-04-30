/* Includes ------------------------------------------------------------------*/
 #include "stm32f4xx.h"
/**
  ******************************************************************************
  * @file    Lab-Optimization/main.c 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    19-06-2019
  *****************************************************************************/
volatile unsigned short int *RCC_AHB1ENR = (unsigned short int *) 0x40023830; 

// determiner l'adresse de register GPIOD_MODER
volatile unsigned  int *GPIOD_MODER = (unsigned int *) 0x40020C00;  

// determiner l'adresse de register GPIOD_ODR
volatile unsigned  int *GPIOD_ODR = (unsigned int *) 0x40020C14;   
                                                       
/* Les etapes : --------------------------------------------------------------*/
// 1) Compiler - telecharger le programmer==> verifier les leds
// 2) changer l'option de l'optimzation ==> high 
// 3) Re-Compiler - telecharger le programmer==> verifier les leds
// 4) expliquer ce changement?  

/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(volatile unsigned  int nCount)
{
  for(; nCount != 0; nCount--);
}

//#define HIGH_FRE
//#define LOW_FRE
#if defined(HIGH_FRE)
#define Temps 0x5FFFFF/5 
#else
#define Temps 0x5FFFFF
#endif

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  // Determiner la valeur de masque pour activer l'horloge de GPIO D
  *RCC_AHB1ENR |= (1<<3) ;
  
  // Determiner la valeur de masque pour préparer la configureation la pin PD12 
  *GPIOD_MODER |=  (1<<24);
  
    // Determiner la valeur de masque pour préparer la configureation la pin PD13
  *GPIOD_MODER |=  (1<<26);


  while(1)
  {
    /* mettre le pin 12 a 1 */
      *GPIOD_ODR |= 0x1000;

    /* mettre le pin 13 a 1 */
      *GPIOD_ODR |= 0x2000;
    
    Delay(Temps);
   
    /* mettre le pin 12 a 0 */
    *GPIOD_ODR &=~ (1<<12);

    /* mettre le pin 13 a 0 */    
    *GPIOD_ODR &= ~(1<<13);
    Delay(Temps);
  }
}


/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/