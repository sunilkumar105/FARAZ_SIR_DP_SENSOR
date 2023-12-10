PROJECT

Measuring differential pressure using sensor and sending its value to the gateway and finally forwarding its value to the MQTT server

there are total two files,
>> F103 IS based on STM32F103C8T6 controller

>> Another DP_TEST is based on STM32F401CCU6


DEV_1 branch overview
1. Made the new branch dev_1
2. In this branch i will update the program to receive the file by UART.... and will store the address in flash...whenever it will reboot it will read address from the flash and will initialize the nrf with that address

3. Configuration for stm32f103c8t6 added in dp sensor, check it after reaching home, also there is a #ifdef of F103X8T6 , check it for voltage setting of flash