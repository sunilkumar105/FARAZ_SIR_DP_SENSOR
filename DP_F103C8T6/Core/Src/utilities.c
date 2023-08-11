/*
 * utilities.c
 *
 *  Created on: Aug 8, 2023
 *      Author: sunil
 */

#include "utilities.h"
extern ADC_HandleTypeDef hadc1;

void send_DP_sensor_value_to_gateway(void) {
	HAL_ADC_Start(&hadc1); //TAKE SAMPLE
	HAL_ADC_PollForConversion(&hadc1, 100);
	uint32_t adc_val = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	char adc_str[32]; //UINT32_T TO CHAR ARRAY CONVERSION
	sprintf(adc_str, "%lu", adc_val);
	adc_str[6] = '\r';
	memcpy(adc_str,"abcdefghijklmnopq      d",32);
	TRANSMITT_UPDATE_TO_GATEWAY(adc_str); //TRANSMITT MESSAGE TO GATEWAY
}
void HANDLE_RECEIVED_MESSAGE_FROM_GATEWAY(void){
	//check for availability of message
	//take action according to the message
}
