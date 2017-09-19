/*
 * serial.h
 *
 *  Created on: 19 Sep 2017
 *      Author: viper
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#pragma once
#include "stm32f0xx_conf.h"
#include "stm32f0xx_usart.h"
#include "pins.h"

USART_InitTypeDef usartStruct;
USART_ClockInitTypeDef usartClock;
GPIO_InitTypeDef usartPinStruct;

// USART1 Pins: Rx (PA2), Tx (PA3)
#define USART1_RX GPIO_Pin_2
#define USART1_TX GPIO_Pin_3
#define USART1_PORT GPIOA

uint32_t baudRate;
extern uint32_t baudRates[];

void setupSerial();
void setBaudRate(uint32_t);
uint8_t getByteSync(USART_TypeDef *);
void sendByteSync(USART_TypeDef *, uint8_t);
void sendString(USART_TypeDef *, char *);

#endif /* SERIAL_H_ */
