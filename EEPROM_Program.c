

#include <util/delay.h>
/* Include Header Files From LIB */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"


/* Include My own Header Files*/
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"

/* Include Header Files From MCAL Layer */
#include "DIO_interface.h"
#include "I2C_Interface.h"



void EEPROM_voidSendDataByte ( u16 Copy_u16LocationAddress , u8 Copy_u8DataByte )
{
    u8 Local_Address ;

    //Local_Address = EEPROM_FIXED_ADDRESS_W | (EEPROM_A2<<2) | ((u8)(Copy_u16LocationAddress>>8));

    Local_Address = EEPROM_FIXED_ADDRESS_W | (  (Copy_u16LocationAddress>>8) << 1 );

    // Send Start Condition
    I2C_Master_u8StartCondition();
    // Send the address packet
    I2C_Master_u8WriteDataByte_ACK(Local_Address);
    // send the rest 8 BITS of the location Address
    I2C_Master_u8WriteDataByte_ACK( (u8)(Copy_u16LocationAddress));
    // Send The Data Byte to the Memory Location
    I2C_Master_u8WriteDataByte_ACK(Copy_u8DataByte);
    // Send Stop Condition
    I2C_Master_u8StopCondition();
    // Delay Until the Write cycle is finished
    _delay_ms(10);

}

u8 EEPROM_voidReadDataByte ( u16 Copy_u16LocationAddress )
{
    u8 Data ;

    u8 Local_Address;

    Local_Address = EEPROM_FIXED_ADDRESS_W | ( ((u8)(Copy_u16LocationAddress>>8)) << 1) ;
    // Send Start Condition 
    I2C_Master_u8StartCondition ();
    // Send the address packet with Write operation
    I2C_Master_u8WriteDataByte_ACK (Local_Address);
    // send the rest 8 BITS of the location Address
    I2C_Master_u8WriteDataByte_ACK ( (u8)(Copy_u16LocationAddress) );
    // Send Repeated Start to change write request to Read request
    I2C_Master_u8ReStartCondition ();
    // Send the address packet with Read operation
    I2C_Master_u8WriteDataByte_ACK(EEPROM_FIXED_ADDRESS_R);
    // Get The Data From Memory
    I2C_Master_u8ReadDataByte_NOTACK(&Data);
    // Send Stop Condition
    I2C_Master_u8StopCondition();
    // Delay Until the Read cycle is finished
    _delay_ms(10);
    // Return Data
    return Data ;
}
