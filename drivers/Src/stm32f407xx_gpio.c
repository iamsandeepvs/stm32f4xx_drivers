/*
 * stm32f407xx_gpio.c
 *
 *
 */

#include "stm32f407xx_gpio.h"


/*Initialization and De-initialization*/
/*
 * @function          - GPIO_Init
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Pointer to the GPIO handle
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t temp = 0;

	if((pGPIOHandle->GPIO_PinConfig.GPIO_PinMode)<=GPIO_MODE_ANALOG){
		temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //Each pin takes 2 bit-fields
		pGPIOHandle->pGPIOx->MODER |= temp;
	}

	temp = 0;
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl <<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |=temp;

	temp = 0;
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |=temp;

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
		uint32_t temp1,temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode<<(4*temp2));
	}

}

/*
 * @function          - GPIO_Denit
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Base address of the GPIO Port
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

}

/*Peripheral Clock Setup
 * @function          - GPIO_PeriClockControl
 * @description       - This function Enables or Disables the peripheral clock for the given GPIO port
 * @parameter[in]     - Base address of the GPIO peripheral
 * @parameter[in]     - Enable or Disable macro, refer to MCU specific header
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t En_or_Di){
	if(En_or_Di == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG){
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI){
			GPIOI_PCLK_EN();
		}
	}
	else{
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF){
			GPIOF_PCLK_DI();
		}
		else if(pGPIOx == GPIOG){
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx == GPIOH){
			GPIOH_PCLK_DI();
		}
		else if(pGPIOx == GPIOI){
			GPIOI_PCLK_DI();
		}
	}
}

/*************************Data read and Write***********************************/

/*
 * @function          - GPIO_ReadFromInputPin
 * @description       - Reads from a pin on the given port
 * @parameter[in]     - Base address of the GPIO port
 * @parameter[in]     - Pin number of the desired read pin
 * @parameter[in]     - None
 * @return            - Returns the pin state
 * @Note              - None
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * @function          - GPIO_Init
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Pointer to the GPIO handle
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - Returns the
 * @Note              - None
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

/*
 * @function          - GPIO_Init
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Pointer to the GPIO handle
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);

/*
 * @function          - GPIO_Init
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Pointer to the GPIO handle
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

/*
 * @function          - GPIO_Init
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Pointer to the GPIO handle
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*IRQ Configuration and Handling*/

/*
 * @function          - GPIO_Init
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Pointer to the GPIO handle
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t En_or_Di);

/*
 * @function          - GPIO_Init
 * @description       - This function initializes the given GPIO port
 * @parameter[in]     - Pointer to the GPIO handle
 * @parameter[in]     - None
 * @parameter[in]     - None
 * @return            - None
 * @Note              - None
 */
void GPIO_IRQHandling(uint8_t PinNumber);
