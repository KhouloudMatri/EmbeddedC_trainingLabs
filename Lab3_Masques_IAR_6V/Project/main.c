/* Includes ------------------------------------------------------------------*/
 #include "stm32f4xx.h"
/**
  ******************************************************************************
  * @file    Lab-masques/main.c 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    19-06-2019
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
 #include "stm32f4xx.h"

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup Lab
  * @{
  */ 

/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 100
/* Private variables ---------------------------------------------------------*/

// determiner l'adresse de register RCC_AHB1ENR pour activer l'horlge de GPIO D
volatile unsigned short int *RCC_AHB1ENR =(unsigned short int*)(0x40023800+0x30);

// determiner l'adresse de register GPIOD_MODER
volatile unsigned  int *GPIOD_MODER =(unsigned  int*)(0x40020C00+0x00); 

// determiner l'adresse de register GPIOD_ODR
volatile unsigned  int *GPIOD_ODR =(unsigned  int*)(0x40020C00+0x14); 

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nCount);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  
  unsigned  int counter = 0x00;  

  // Determiner la valeur de masque pour activer l'horloge de GPIO D
  *RCC_AHB1ENR |= (1<<3);
  
  // Determiner la valeur de masque pour préparer la configureation la pin PD12 
  *GPIOD_MODER |= (1<<24);
  *GPIOD_MODER &= ~(1<<25);
  
    // Determiner la valeur de masque pour préparer la configureation la pin PD13
  *GPIOD_MODER |= (1<<26);
  *GPIOD_MODER &= ~(1<<27);
  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
   /* mettre le pin 12 a 1 */
    *GPIOD_ODR |= (1<<12);
   /* mettre le pin 13 a 1 */
    *GPIOD_ODR |= (1<<13);
    Delay(0x5FFFFF) ;

    /* mettre le pin 12 a 0 */
    *GPIOD_ODR &= ~(1<<12);
    /* mettre le pin 13 a 0 */    
    *GPIOD_ODR &= ~(1<<13);
    Delay(0x5FFFFF) ;
           
  }  
  while (1)
  {}
}

/**
  * @brief  Delay Function.
  * @param  nCount:specifies the Delay time length.
  * @retval None
  */
void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/
