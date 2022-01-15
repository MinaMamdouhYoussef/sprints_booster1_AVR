/*
 * main.c
 *
 *  Created on: Jan 10, 2022
 *      Author: CompuSity
 */

#include"primitive_data_types.h"
#include "BIT_MATH.h"
#include "dio_interface.h"
#include "atmega32_registers.h"
#include "timers_interface.h"
#include "led_interface.h"


extern uint8_t gu8_FinishIntWaitFlag ;
#define bit7			7

int main()
{
	uint8_t u8_PinState ;
	LED_voidInit() ;
	TIMERS_voidInit() ;
	TIMER0_u8StartWithclockAndPrescalerSelect(u8_INTERNAL_CLK_PRE_8) ;
	SET_BIT(Ru8_SREG , bit7); // set global interrupt
	TIMER0_u8InterruptWait(500) ;
	while(1)
	{
		DIO_u8GetPinVal(u8_DIO_PORTB,u8_DIO_PIN4,&u8_PinState) ;
		if(gu8_FinishIntWaitFlag==u8_FINISH_INTERRUPT_WAITING && u8_PinState == u8_DIO_PIN_LOW)
		{
			LED_u8On(u8_LED0) ;
			TIMER0_u8InterruptWait(300) ;
		}
		else if(gu8_FinishIntWaitFlag==u8_FINISH_INTERRUPT_WAITING && u8_PinState == u8_DIO_PIN_HIGH)
		{
			LED_u8Off(u8_LED0) ;
			TIMER0_u8InterruptWait(500) ;
		}
	}
return 1 ;
}
