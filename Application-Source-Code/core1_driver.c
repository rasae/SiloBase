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
				Generate_Keys(31);
				if (e > 255)
				{
					int temp = e & 0xFF00;
					temp = temp >> 8;
					int highByte = temp;
					temp = e & 0x00FF;
					int lowByte = temp;
					Send_Byte(highByte);
					Send_Byte(lowByte);
//					Send_Byte(((char)e | 0xFF00) >> 8);
//					Send_Byte((char)e | 0x00FF);
				}
				else Send_Byte(e);

				if (publicKey > 255)
				{
					int temp = publicKey & 0xFF00;
					temp = temp >> 8;
					char highByte = (char) temp;
					temp = publicKey & 0x00FF;
					char lowByte = (char)temp;
					Send_Byte(highByte);
					Send_Byte(lowByte);
//					Send_Byte((char)(publicKey | 0xFF00) >> 8);
//					Send_Byte((char)publicKey | 0x00FF);
				}
				else Send_Byte(publicKey);

				//receive encrypted_data
				int userEncryptedHigh = Receive_Byte();
				int userEncryptedLow = Receive_Byte();
				rawData = Receive_Byte();
				userEncryptedHigh = userEncryptedHigh << 8;
				encryptedData = userEncryptedHigh | userEncryptedLow;
				int randomPass = random_num() % 255;
				Send_Byte(randomPass);
				//display the encryptedData on right 4 seven segment displays
				Display_Data(encryptedData);
				//we jump here because they want to do password confirmation

				Check_Input2(randomPass,rawData);

				if (wrongFlag)
				{
					int counter = 0;
					Dec_to_Hex(13522);
					while(1){
						SSeg_En(0b11110111);
						SSeg_Display(hexRep[i-1]);
						usleep(500);
						SSeg_En(0b11111011);
						SSeg_Display(hexRep[i-2]);
						usleep(500);
						SSeg_En(0b11111101);
						SSeg_Display(hexRep[i-3]);
						usleep(500);
						SSeg_En(0b11111110);
						SSeg_Display(hexRep[i-4]);
						usleep(500);
						counter++;
						//Check_Input2(privateKey,data);

						if (counter == 5000) break;	//if new data was sent exit.

					}//end while(1)

					SSeg_En(0x00);
					SSeg_Display(0xFF);
				}

				else
				{
					SSeg_En(0x00);
					SSeg_Display(0xFF);
				}

				//generate randomPasscode for user to retrieve data
				//send to user

			}//end if( ping == 'C')

		}//end while(1)

	}//end else





	return XST_SUCCESS;
}//end main();

