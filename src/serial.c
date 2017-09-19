/*
 * serial.c
 *
 *  Created on: 19 Sep 2017
 *      Author: viper
 */

#include "serial.h"

void setupSerial() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	pinSetup(usartPinStruct, USART1_RX | USART1_TX, GPIO_Mode_AF, GPIO_Speed_2MHz, GPIO_OType_PP,
			GPIO_PuPd_UP, USART1_PORT);
	GPIO_PinAFConfig(USART1_PORT, GPIO_PinSource2, GPIO_AF_1);
	GPIO_PinAFConfig(USART1_PORT, GPIO_PinSource3, GPIO_AF_1);
	// Configure USART
	USART_StructInit(&usartStruct);
}
