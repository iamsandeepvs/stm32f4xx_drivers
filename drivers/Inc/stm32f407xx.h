/*
 * stm32f407xx.h
 *
 *
 *  Author: iamsa
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>

/*
 * Base addresses for  the flash and SRAM memories
 */

#define FLASH_BASEADDR        	0x08000000U       /*Base address for main flash memory*/
#define SRAM1_BASEADDR       	0x20000000U       /*Base address for SRAM1*/
#define SRAM2_BASEADDR        	0x2001C000U       /*Base address for SRAM2 = SRAM1+112KB*/
#define ROM_BASEADDR          	0x1FFF0000U       /*Base address for system memory*/
#define OTP_BASEADDR          	0x1FFF7800U       /*Base address for OTP area*/
#define SRAM                  	SRAM1_BASEADDR

/*
 * AHBx and APBx Bus peripheral base addresses
 */

#define PERIPH_BASE            0X40000000U
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE        0X40010000U
#define AHB1PERIPH_BASE        0X40020000U
#define AHB2PERIPH_BASE        0X50000000U

/*
 * Base addresses for peripherals on the AHB1 bus
 */

#define GPIOA_BASEADDR         (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR         (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR         (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR         (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR         (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR         (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR         (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR         (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR         (AHB1PERIPH_BASE + 0x2000)
#define GPIOJ_BASEADDR         (AHB1PERIPH_BASE + 0x2400)
#define GPIOK_BASEADDR         (AHB1PERIPH_BASE + 0x2800)
#define RCC_BASEADDR           (AHB1PERIPH_BASE + 0x3800)

/*
 * Base addresses for peripherals on the APB1 bus
 */

#define SPI2_BASEADDR          (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR          (APB1PERIPH_BASE + 0x3C00)

#define USART2_BASEADDR        (APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR        (APB1PERIPH_BASE + 0x4800)
#define UART4_BASEADDR         (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR         (APB1PERIPH_BASE + 0x5000)

#define I2C1_BASEADDR          (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR          (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR          (APB1PERIPH_BASE + 0x5C00)

/*
 * Base addressed for  peripherals on APB2 bus
 */

#define USART1_BASEADDR        (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR        (APB2PERIPH_BASE + 0x1400)

#define SPI1_BASEADDR          (APB2PERIPH_BASE + 0x3000)

#define SYSCFG_BASEADDR        (APB2PERIPH_BASE + 0x3800)
#define EXTI_BASEADDR          (APB2PERIPH_BASE + 0x3C00)

/******************Peripheral register definition structures*******************/

/*
 * Register definition for GPIO
 */

typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRRL;
	volatile uint32_t BSRRH;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	         uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	         uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	         uint32_t RESERVED2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	         uint32_t RESERVED3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	         uint32_t RESERVED4;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	         uint32_t RESERVED5[2];
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	         uint32_t RESERVED6[2];
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCKCFGR;
}RCC_RegDef_t;


#define GPIOA              ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB              ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC              ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD              ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE              ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF              ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG              ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH              ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI              ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC                ((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()    (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()    (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN()    (RCC->AHB1ENR |= (1<<8))

/*
 *  Clock Enable Macros for I2C peripherals
 */

#define I2C1_PCLK_EN()      (RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()      (RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()      (RCC->APB1ENR |= (1<<23))

/*
 *  Clock Enable Macros for SPI peripherals
 */

#define SPI1_PCLK_EN()      (RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()      (RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()      (RCC->APB1ENR |= (1<<15))

/*
 *  Clock Enable Macros for UART peripherals
 */

#define USART1_PCLK_EN()     (RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_EN()     (RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN()     (RCC->APB1ENR |= (1<<18))
#define UART4_PCLK_EN()      (RCC->APB1ENR |= (1<<19))
#define UART5_PCLK_EN()      (RCC->APB1ENR |= (1<<20))
#define USART6_PCLK_EN()     (RCC->APB2ENR |= (1<<5))

/*
 *  Clock Enable Macros for SYSCFG peripheral
 */

#define SYSCFG_PCLK_EN()     (RCC->APB2ENR |= (1<<14))

/*
 *  Clock Disable Macros for GPIO peripherals
 */

#define  GPIOA_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<0))
#define  GPIOB_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<1))
#define  GPIOC_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<2))
#define  GPIOD_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<3))
#define  GPIOE_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<4))
#define  GPIOF_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<5))
#define  GPIOG_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<6))
#define  GPIOH_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<7))
#define  GPIOI_PCLK_DI()       (RCC->AHB1ENR &= ~(1<<8))

/*
 *  Clock Disable Macros for I2C peripherals
 */

#define I2C1_PCLK_DI()         (RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()         (RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()         (RCC->APB1ENR &= ~(1<<23))

/*
 * Clock Disable Macros for SPI peripherals
 */

#define SPI1_PCLK_DI()          (RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()          (RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()          (RCC->APB1ENR &= ~(1<<15))

/*
 *  Clock Disable Macros for USART peripherals
 */

#define USART1_PCLK_DI()        (RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI()        (RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI()        (RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DI()         (RCC->APB1ENR &= ~(1<<19))
#define UART5_PCLK_DI()         (RCC->APB1ENR &= ~(1<<20))
#define USART6_PCLK_DI()        (RCC->APB2ENR &= ~(1<<5))

/*
 *  SYSCGF Disable Macro
 */

#define SYSCFG_PCLK_DI()         (RCC->APB2ENR &= ~(1<<14))

/*
 *  Generic Macros
 */

#define ENABLE                   1
#define DISABLE                  0
#define SET                      ENABLE
#define RESET                    DISABLE
#define GPIO_PIN_SET             SET
#define GPIO_PIN_RESET           RESET

#endif /* INC_STM32F407XX_H_ */
