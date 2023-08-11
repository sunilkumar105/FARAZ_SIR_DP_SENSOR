/*
 * nrf_helper.c
 *
 *  Created on: Aug 8, 2023
 *      Author: sunil
 */

#include "nrf_helper.h"

uint64_t node_pipe_addr = 0x11223344cc;
uint8_t node_channel_addr = 52;
uint64_t target_pipe_addr = 0x11223344aa;
uint8_t target_channel_addr = 52;

extern SPI_HandleTypeDef hspi2;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
#define NRF_SPI_PORT hspi2

void nrf_init(void) {
	NRF24_begin(CE_PIN_GPIO_Port, CSN_PIN_Pin, CE_PIN_Pin, NRF_SPI_PORT);
	nrf24_DebugUART_Init(huart2);
	NRF24_setAutoAck(true);
	NRF24_setPayloadSize(32);
//	NRF24_stopListening();
//	NRF24_openWritingPipe(target_pipe_addr);
//	NRF24_setChannel(node_channel_addr);
	printRadioSettings();
}
void Switch_to_Transmitt_mode(void) {
	NRF24_stopListening();
	NRF24_openWritingPipe(target_pipe_addr);
	NRF24_setChannel(target_channel_addr);
}
void Switch_to_Receiver_mode(void) {
	NRF24_openReadingPipe(1, node_pipe_addr);
	NRF24_setChannel(node_channel_addr);
	NRF24_startListening();
}
void TRANSMITT_UPDATE_TO_GATEWAY(char my_tx_data[]) {
	for (int i = 0; i < +10; i++) {
		if (!NRF24_write(my_tx_data, 32)) {
			NRF24_write(my_tx_data, 32);
			HAL_UART_Transmit(&huart2,
					(uint8_t*) "Transmitt_update waiting for ack\n",
					strlen("Transmitt_update waiting for ack\n"), 10);
			HAL_Delay(200);
		} else {
			HAL_UART_Transmit(&huart2,
					(uint8_t*) "Transmitt_update Transmitted successfully\n",
					strlen("Transmitt_update Transmitted successfully\n"), 10);
			HAL_Delay(100);
			break;
		}
	}
}
