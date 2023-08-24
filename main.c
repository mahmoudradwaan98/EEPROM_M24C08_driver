/*
 * main.c
 *
 *  Created on: Aug 6, 2023
 *      Author: User
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "I2C_Interface.h"
#include "DIO_interface.h"
#include "EEPROM_Interface.h"

void main (void){



	I2C_voidMasterInit(SCL_400KHZ);

	//EEPROM_voidSendDataByte(0,15);

	EEPROM_voidReadDataByte(0);

	while(1){

	}

}
