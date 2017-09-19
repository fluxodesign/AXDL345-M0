/*
 * serial.c
 *
 *  Created on: 19 Sep 2017
 *      Author: viper
 */

#include "serial.h"

uint32_t baudRate = 9600;
uint32_t baudRates[] = { 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 250000, 230400, 460800, 921600 };

void setupSerial() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	pinSetup(usartPinStruct, USART1_RX | USART1_TX, GPIO_Mode_AF, GPIO_Speed_2MHz, GPIO_OType_PP,
			GPIO_PuPd_UP, USART1_PORT);
	GPIO_PinAFConfig(USART1_PORT, GPIO_PinSource2, GPIO_AF_1);
	GPIO_PinAFConfig(USART1_PORT, GPIO_PinSource3, GPIO_AF_1);
	// Configure USART
	USART_StructInit(&usartStruct);
	usartStruct.USART_BaudRate = baudRate;
	USART_OverSampling8Cmd(USART1, ENABLE);
	USART_Init(USART1, &usartStruct);
	USART_Cmd(USART1, ENABLE);
	sendString(USART1, "FD Serial ready...\r\n");
}

void setBaudRates(uint32_t value) {
	for (int i = 0; i < sizeof(baudRates); i++) {
		if (baudRates[i] == value) {
			baudRate = value;
			break;
		}
	}
}

uint8_t getByteSync(USART_TypeDef *usartTD) {
	while (USART_GetFlagStatus(usartTD, USART_FLAG_RXNE) == RESET) {
	}
	return USART_ReceiveData(usartTD);
}

void sendByteSync(USART_TypeDef *usartTD, uint8_t byte) {
	while (USART_GetFlagStatus(usartTD, USART_FLAG_TXE) == RESET) {
	}
	USART_SendData(usartTD, byte);
}

void sentPacket(USART_TypeDef *usartTD, uint8_t *data, uint16_t length) {
	uint16_t x = 0;
	while (x < length) {
		sendByteSync(usartTD, data[x]);
		x++;
	}
}

void sendString(USART_TypeDef *usartTD, char *str) {
	uint16_t length = 0;
	while (str[length] != '\0') {
		sendByteSync(usartTD,  str[length]);
		length++;
	}
}
