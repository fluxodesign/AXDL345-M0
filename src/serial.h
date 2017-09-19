/*
 * serial.h
 *
 *  Created on: 19 Sep 2017
 *      Author: viper
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include "stm32f0xx_conf.h"
#include "pins.h"

USART_InitTypeDef usartStruct;
USART_ClockInitTypeDef usartClock;
GPIO_InitTypeDef usartPinStruct;

// USART1 Pins: Rx (PA2), Tx (PA3)
#define USART1_RX GPIO_Pin_2
#define USART1_TX GPIO_Pin_3
#define USART1_PORT GPIOA

void setupSerial();

#endif /* SERIAL_H_ */
