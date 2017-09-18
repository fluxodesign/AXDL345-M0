/*
 * pins.c
 *
 *  Created on: 18Sep.,2017
 *      Author: viper
 */

#include "pins.h"

void pinSetup(GPIO_InitTypeDef iopin, uint32_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, GPIOOType_TypeDef oType,
		GPIOPuPd_TypeDef pupd, GPIO_TypeDef * port) {
	iopin.GPIO_Pin = pin;
	iopin.GPIO_Mode = mode;
	iopin.GPIO_Speed = speed;
	iopin.GPIO_OType = oType;
	iopin.GPIO_PuPd = pupd;
	GPIO_Init(port, &iopin);
}

void sleepMilis(uint32_t milis) {
	volatile uint32_t msStart = t_miliseconds;
	while ((t_miliseconds - msStart) < milis) {
		asm volatile("nop");
	}
}

void sleepSeconds(uint32_t seconds) {
	volatile uint32_t sStart = t_seconds;
	while ((t_seconds - sStart) < seconds) {
		asm volatile("nop");
	}
}
