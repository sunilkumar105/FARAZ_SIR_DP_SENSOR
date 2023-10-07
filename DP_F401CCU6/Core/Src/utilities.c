/*
 * utilities.c
 *
 *  Created on: Aug 8, 2023
 *      Author: sunil
 */

#include "utilities.h"

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
//check for availability of message
	if (NRF24_available()) {
		char received_data_from_nodes[50];
		NRF24_read(received_data_from_nodes, 32);
		//take action according to the message
	}
}
