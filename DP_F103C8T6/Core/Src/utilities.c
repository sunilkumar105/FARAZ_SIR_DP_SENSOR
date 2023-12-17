/*
 * utilities.c
 *
 *  Created on: Aug 8, 2023
 *      Author: sunil
 */

#include "utilities.h"
extern UART_HandleTypeDef huart2;
char my_node_id[2] = "01";

void send_DP_sensor_value_to_gateway(void) {

	uint32_t PRESSURE = READ_PRESSURE();
	char buffer[20];
	sprintf(buffer, "%u", PRESSURE);

	char my_tx_data[32] = "010";
	my_tx_data[3] = buffer[0];
	my_tx_data[4] = buffer[1];
	my_tx_data[5] = buffer[2];
	my_tx_data[5] = '\r';
	my_tx_data[5] = '\n';
	TRANSMITT_UPDATE_TO_GATEWAY(my_tx_data); //TRANSMITT MESSAGE TO GATEWAY
}
void HANDLE_RECEIVED_MESSAGE_FROM_GATEWAY(void) {
	char received_data_from_gateway[50] = "";
	HAL_UART_Transmit(&huart2, (uint8_t*) "\n DATA RECEIVED FROM NRF::>> ",
			strlen("\n DATA RECEIVED FROM NRF::>> "), 10);
	NRF24_read(received_data_from_gateway, 5); //store received data
	HAL_UART_Transmit(&huart2, (uint8_t*) received_data_from_gateway, 5, 10);
	char rcvd_node_id[2];
	memcpy(rcvd_node_id, received_data_from_gateway, 2);
	char rcvd_command = received_data_from_gateway[2];

	//============CHECK IF NODE MATCH WITH ID======================//
	if (!(memcmp(rcvd_node_id, my_node_id, 2))) {
		HAL_UART_Transmit(&huart2, (uint8_t*) "\n NODE ID MATCHED",
				strlen("\n NODE ID MATCHED"), 10);
	} else {
		return;
	}
	//Read the command and transmitt the DP SENSOR VAL
	if (rcvd_command == '0') {
		//transmitt a valuye
		HAL_UART_Transmit(&huart2, (uint8_t*) "\n TRANSMITTING DP DATA",
				strlen("\n TRANSMITTING DP DATA"), 10);
		send_DP_sensor_value_to_gateway();
	}
}
