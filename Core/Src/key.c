/*
 * key.c
 *
 *  Created on: Oct 4, 2026
 *      Author: ASUS
 */
#include "key.h"

int Key_Scan(void){
	if(HAL_GPIO_ReadPin(KEY_NEXT_GPIO_Port, KEY_NEXT_Pin)==GPIO_PIN_RESET){
	    while(HAL_GPIO_ReadPin(KEY_NEXT_GPIO_Port, KEY_NEXT_Pin)==GPIO_PIN_RESET){}
		return 1;

	}
	else if(HAL_GPIO_ReadPin(KEY_CHOICE_GPIO_Port, KEY_CHOICE_Pin)==GPIO_PIN_RESET){

		while(HAL_GPIO_ReadPin(KEY_CHOICE_GPIO_Port, KEY_CHOICE_Pin)==GPIO_PIN_RESET){}
		return 2;

	}
	else if(HAL_GPIO_ReadPin(KEY_RETURN_GPIO_Port, KEY_RETURN_Pin)==GPIO_PIN_RESET){

			while(HAL_GPIO_ReadPin(KEY_RETURN_GPIO_Port, KEY_RETURN_Pin)==GPIO_PIN_RESET){}
		return 3;

		}
	else{
		return 0;
	}
}
