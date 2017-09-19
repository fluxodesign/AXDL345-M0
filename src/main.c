/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include "stm32f0_discovery.h"
#include "pins.h"
#include "serial.h"

void setup(void);

/*
 * For this first version, we are going to play with the USER LEDs:
 * - Green LED (LD3): PC9
 * - Blue LED (LD4): PC8
 */
GPIO_InitTypeDef Pin_Green;
GPIO_InitTypeDef Pin_Blue;

int main(void){
	setup();

	while (1) {
		// Blue
		GPIO_SetBits(LED4_GPIO_PORT, LED4_PIN);
		sleepMilis(500);
		GPIO_ResetBits(LED4_GPIO_PORT, LED4_PIN);
		// Green
		GPIO_SetBits(LED3_GPIO_PORT, LED3_PIN);
		sleepMilis(500);
		GPIO_ResetBits(LED3_GPIO_PORT, LED3_PIN);
	}
}

void SysTick_Handler() {
	t_miliseconds++;
	if (t_miliseconds % 1000 == 999) {
		t_seconds++;
	}
}

void setup() {
	SystemInit();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / MilisecondsIT);

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	t_miliseconds = t_seconds = 0;

	pinSetup(Pin_Green, LED3_PIN, GPIO_Mode_OUT, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_UP, LED3_GPIO_PORT);
	pinSetup(Pin_Blue, LED4_PIN, GPIO_Mode_OUT, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_UP, LED4_GPIO_PORT);
	setupSerial();
}
