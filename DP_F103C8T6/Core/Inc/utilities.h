/*
 * utilities.h
 *
 *  Created on: Aug 8, 2023
 *      Author: sunil
 */

#ifndef INC_UTILITIES_H_
#define INC_UTILITIES_H_

#include <string.h>
#include <stdio.h>
#include "main.h"
#include "stm32f1xx_hal.h"
#include "nrf_helper.h"

void send_DP_sensor_value_to_gateway(void);
void HANDLE_RECEIVED_MESSAGE_FROM_GATEWAY(void);


#endif /* INC_UTILITIES_H_ */
