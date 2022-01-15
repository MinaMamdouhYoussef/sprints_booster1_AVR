/*
 * main.c
 *
 *  Created on: Jan 10, 2022
 *      Author: CompuSity
 */

#include"primitive_data_types.h"
#include "BIT_MATH.h"
#include "dio_interface.h"
#include "timers_interface.h"
#include "led_interface.h"

int main()
{
	TIMERS_voidInit() ;
	LED_voidInit() ;
	while(1)
	{
		LED_u8On(u8_LED0) ;
		TIMER0_u8BusyWait(300) ;
		LED_u8Off(u8_LED0) ;
		TIMER0_u8BusyWait(500) ;

	}
return 1 ;
}
