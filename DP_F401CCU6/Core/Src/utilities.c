/*
 * utilities.c
 *
 *  Created on: Aug 8, 2023
 *      Author: sunil
 */

#include "utilities.h"

void send_DP_sensor_value_to_gateway(void) {

//	TRANSMITT_UPDATE_TO_GATEWAY(adc_str); //TRANSMITT MESSAGE TO GATEWAY
}
void HANDLE_RECEIVED_MESSAGE_FROM_GATEWAY(void) {
	//check for availability of message
	if (NRF24_available()) {
		char received_data_from_nodes[50];
		NRF24_read(received_data_from_nodes, 32);
		//take action according to the message
	}
}