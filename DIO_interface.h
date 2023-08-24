/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : DIO                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#ifndef DIO_interface_H_

 #define DIO_interface_H_

typedef union{

    unsigned char Reg;

    struct {

        unsigned char B0:1;
        unsigned char B1:1;
        unsigned char B2:1;
        unsigned char B3:1;
        unsigned char B4:1;
        unsigned char B5:1;
        unsigned char B6:1;
        unsigned char B7:1;

    }bit;

}Register;

typedef enum {

	DIO_U8PIN_INPUT =0,

	DIO_U8PIN_OUTPUT=1

}pin_direction;

typedef enum {

	DIO_U8PIN_LOW =0,

	DIO_U8PIN_HIGH=1

}pin_value;

typedef enum {

	DIO_U8PORT_INPUT =0,

	DIO_U8PORT_OUTPUT=1

}port_direction;

typedef enum {

	DIO_U8PORT_LOW =0,

	DIO_U8PORT_HIGH=1

}port_value;

typedef enum {

	DIO_U8PORTA =0,

	DIO_U8PORTB=1,
	DIO_U8PORTC=2,
	DIO_U8PORTD=3

}port_name;

typedef enum {

 DIO_U8PIN0 = 0,
 DIO_U8PIN1 = 1,
 DIO_U8PIN2 = 2,
 DIO_U8PIN3 = 3,
 DIO_U8PIN4 = 4,
 DIO_U8PIN5 = 5,
 DIO_U8PIN6 =  6,
 DIO_U8PIN7 = 7

}pin_index;

typedef enum {

	DIO_enuNOK =0,

	DIO_enuOK=1

}DIO_tenuErrorStatus;

	u8 MCAL_DIO_u8SetPinDirection(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction);
	
	u8 MCAL_DIO_u8SetPortDirection(u8 copy_u8port,u8 copy_u8direction);
	
	u8 MCAL_DIO_u8SetPinValue(u8 copy_u8port,u8 copy_u8pin, u8 copy_u8value);
	
	u8 MCAL_DIO_u8SetPortValue(u8 copy_u8port, u8 copy_u8value);
	
	u8 MCAL_DIO_u8GetPinValue(u8 copy_u8port,u8 copy_u8pin,u8* copy_pu8value);
	
	u8 MCAL_DIO_u8TogglePinValue(u8 copy_u8port,u8 copy_u8pin);


#endif
