#include "primitive_data_types.h"
#include "dio_interface.h"
#include "buttons_interface.h"
#include "timers_interface.h"

void BUTTONS_voidInit(void) 
{
	DIO_u8SetPinDir(u8_BUTTON2_PORT,u8_BUTTON2_COL,u8_DIO_OUTPUT_PIN)          ;
	DIO_u8SetPinDir(u8_BUTTON2_PORT,u8_BUTTON2_ROW,u8_DIO_INPUT_PIN)           ;
	DIO_u8SetPinVal(u8_BUTTON2_PORT,u8_BUTTON2_COL,u8_DIO_PIN_LOW)			;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////


uint8_t BUTTONS_u8GetRead(uint8_t u8_buttonNum,uint8_t* pu8_buttonReturnVal)
{
	uint8_t u8_ReturnErrorFlag = u8_BUTTON_OK ; 
	if(u8_buttonNum==u8_BUTTON2 && pu8_buttonReturnVal!=NULL_POINTER)
	{
		DIO_u8GetPinVal(u8_BUTTON2_PORT,u8_BUTTON2_ROW,pu8_buttonReturnVal);
		TIMER0_u8BusyWait(u8_DEBOUNCING_TIME_mS) ;
	}
	else 
	{
		u8_ReturnErrorFlag = u8_BUTTON_NOK ; 
	}
	return u8_ReturnErrorFlag ;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t BUTTONS_u8PullUpEn(uint8_t u8_buttonNum)
{
	uint8_t u8_ReturnErrorFlag = u8_BUTTON_OK ; 
	if(u8_buttonNum==u8_BUTTON2)
	{
		DIO_u8SetPinVal(u8_BUTTON2_PORT,u8_BUTTON2_ROW,u8_DIO_PIN_HIGH) ;
		DIO_voidEnablePullUps() ; 
	}
	else 
	{
		u8_ReturnErrorFlag = u8_BUTTON_NOK ; 
	}
	return u8_ReturnErrorFlag ;

}
