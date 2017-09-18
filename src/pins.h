/*
 * pins.h
 *
 *  Created on: 18Sep.,2017
 *      Author: viper
 */

#ifndef PINS_H_
#define PINS_H_

#include "stm32f0xx_conf.h"

#define MilisecondsIT 1000

volatile uint32_t t_miliseconds;
volatile uint32_t t_seconds;

void pinSetup(GPIO_InitTypeDef, uint32_t, GPIOMode_TypeDef, GPIOSpeed_TypeDef, GPIOOType_TypeDef, GPIOPuPd_TypeDef, GPIO_TypeDef *);
void sleepSeconds(uint32_t);
void sleepMilis(uint32_t);

#endif /* PINS_H_ */
