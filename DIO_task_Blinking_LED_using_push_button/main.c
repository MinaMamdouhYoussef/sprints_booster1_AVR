/*
 * main.c
 *
 *  Created on: Jan 10, 2022
 *      Author: CompuSity
 */
#include "BIT_MATH.h"
#include"atmega32_registers.h"
#include"primitive_data_types.h"
#include"dio_interface.h"
#include "timers_interface.h"
#include "buttons_interface.h"
#include "led_interface.h"


#define u8_NOT_PRESSED_YET		0
#define u8_INTIAL_BUTTON_VAL	5
int main()
{
	uint8_t u8_NewButtonVal = u8_INTIAL_BUTTON_VAL ;
	uint8_t u8_PrevButtonVal= u8_INTIAL_BUTTON_VAL ;
	TIMERS_voidInit() ;
	BUTTONS_voidInit() ;
	LED_voidInit() ;
	BUTTONS_u8PullUpEn(u8_BUTTON2) ;

	while(1)
	{
		BUTTONS_u8GetRead(u8_BUTTON2,&u8_NewButtonVal) ;

		if(u8_NewButtonVal==u8_BUTTON_PRESSED && u8_PrevButtonVal!=u8_NewButtonVal)
		{
			LED_u8Tog(u8_LED0) ;
		}
		u8_PrevButtonVal = u8_NewButtonVal ;
	}
return 1 ;
}
