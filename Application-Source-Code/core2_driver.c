/*
 * core1_driver.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Rafed
 */

#include "system_funcs.h"

int main(void){

	if (init_modules() != XST_SUCCESS) return XST_FAILURE;

	else
	{
		while(1)
		{

			char ping = Receive_Byte();
			if (ping == 'C')
			{
				//generate new set of keys and send exponent and modulus value to user
				Generate_Keys(15);

				Send_Byte(e);
				Send_Byte(publicKey);

				//receive encrypted_data
				int userEncrypted = Receive_Byte();
				rawData = Decrypt(userEncrypted);

				int randomPass = random_num() % 255;
				Send_Byte(randomPass);
				Send_Byte_Arduino(privateKey);
				//display the encryptedData on right 4 seven segment displays
				//Display_Data(encryptedData);
				//we jump here because they want to do password confirmation

				//Check_Input2(randomPass,rawData);
				Send_Byte_Arduino(65);
				usleep(100);
				Send_Byte_Arduino(userEncrypted);
				usleep(100);

				while (!button_Pressed()) continue;

				if (Read_Switches() == randomPass)
				{
					Send_Byte_Arduino(5);
					usleep(100);
					Send_Byte_Arduino(rawData);
					usleep(100);
				}

				else
				{
					Send_Byte_Arduino(6);
					usleep(100);
				}



			}//end if( ping == 'C')

		}//end while(1)

	}//end else





	return XST_SUCCESS;
}//end main();

