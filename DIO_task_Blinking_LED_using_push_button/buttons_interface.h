#ifndef __BUTTONS__INTERFACE__
#define __BUTTONS__INTERFACE__

#define u8_BUTTON2_PORT			u8_DIO_PORTC
#define u8_BUTTON2_COL			u8_DIO_PIN6
#define u8_BUTTON2_ROW			u8_DIO_PIN3

#define u8_BUTTON2				11
#define u8_BUTTON_PRESSED		u8_DIO_PIN_LOW
#define u8_BUTTON_NOT_PRESSED	u8_DIO_PIN_HIGH


#define u8_DEBOUNCING_TIME_mS	8

#define u8_BUTTON_OK			12
#define u8_BUTTON_NOK			13


void BUTTONS_voidInit(void) ; 
uint8_t BUTTONS_u8GetRead(uint8_t u8_buttonNum,uint8_t* pu8_buttonReturnVal) ;
uint8_t BUTTONS_u8PullUpEn(uint8_t u8_buttonNum) ;


#endif
