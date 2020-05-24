/*
 * system_funcs.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Rafed
 */

#include "system_funcs.h"
#include <stdlib.h>
#include <sleep.h>


int i2 = 0;
int randNums[20] = {4,8,2,12,56,34,65,32,65,32,654,23,65,43,23,54,76,97,54,32};
char *prime;
unsigned short lfsr = 0xACE1u;
unsigned bit;
int maxE = 13;

void display_private_keys(int input)
{
	int counter = 0;
	Dec_to_Hex(input);

	if (i == 1)	//if its one hex digit, display for 5 seconds
	{
		while(1){
			SSeg_En(0xEF);
			SSeg_Display(hexRep[i-1]);
			usleep(5000000);
			break;
		}//end while
	}

	else if (i == 2)
	{
		while(1){
			SSeg_En(0xDF);
			SSeg_Display(hexRep[i-1]);
			usleep(5000);
			SSeg_En(0xEF);
			SSeg_Display(hexRep[i-2]);
			usleep(5000);
			counter++;
			if (counter == 500) break;
		}//end while
	}

	else if (i == 3)
	{
		while(1){
			SSeg_En(0xBF);
			SSeg_Display(hexRep[i-1]);
			usleep(5000);
			SSeg_En(0xDF);
			SSeg_Display(hexRep[i-2]);
			usleep(5000);
			SSeg_En(0xEF);
			SSeg_Display(hexRep[i-3]);
			usleep(5000);
			counter++;
			if (counter == 333) break;
		}//end while(1)
	}//end if

	else if (i == 4)
	{
		while(1){
			SSeg_En(0x7F);
			SSeg_Display(hexRep[i-1]);
			usleep(5000);
			SSeg_En(0xBF);
			SSeg_Display(hexRep[i-2]);
			usleep(5000);
			SSeg_En(0xDF);
			SSeg_Display(hexRep[i-3]);
			usleep(5000);
			SSeg_En(0xEF);
			SSeg_Display(hexRep[i-4]);
			usleep(5000);
			counter++;
			if (counter == 250) break;
		}
	}
//		SSeg_En(0x7F);
//		SSeg_Display(hexRep[i-1]);
//		usleep(5000);
//		SSeg_En(0xBF);
//		SSeg_Display(hundreds);
//		usleep(5000);
//		SSeg_En(0xDF);
//		SSeg_Display(tenths);
//		usleep(5000);
//		SSeg_En(0xEF);
//		SSeg_Display(ones);
//		usleep(5000);

} //end display_private_keys()

int Read_Switches()
{
	return XGpio_DiscreteRead(&Gpio_Password, PASS_INPUT_CHANNEL);

}//end Read_Switches()

void SSeg_Display(char value)

{
	switch (value)
	{
		case '0':
				value = 0b11000000;
				break;
		case '1':
				value = 0b11111001;
				break;
		case '2':
				value = 0b10100100;
				break;
		case '3':
				value = 0b10110000;
				break;
		case '4':
				value = 0b10011001;
				break;
		case '5':
				value = 0b10010010;
				break;
		case '6':
				value = 0b10000010;
				break;
		case '7':
				value = 0b11111000;
				break;

		case '8':
				value = 0b10000000;
				break;

		case '9':
				value = 0b10011000;
				break;

		case 'A':
				value = 0b10001000;
				break;

		case 'B':
				value = 0b10000011;
				break;

		case 'C':
				value = 0b11000110;
				break;

		case 'D':
				value = 0b10100001;
				break;

		case 'E':
				value = 0b10000110;
				break;

		case 'F':
				value = 0b10001110;
				break;

		default:
				value =  0b11000000;
				break;
	}//end switch

	XGpio_DiscreteWrite(&Gpio_SSEG, SSEG_CHANNEL, value);
}//end Write_SSeg();

void Send_Byte(char value)
{
	XUartLite_SendByte(UART_BASEADDR, value);
}

char Receive_Byte()
{

	return XUartLite_RecvByte(UART_BASEADDR);
}

void SSeg_En(int channel)
{
	XGpio_DiscreteWrite(&Gpio_SSEG, ANODE_CHANNEL,channel);
}

void Display_Data(int data)
{
	//Encrypt(data);
	Dec_to_Hex(data);
	//Dec_to_Hex2(rawData);

	while (1)
	{
			if (i == 1)
			{
				while(1){
					SSeg_En(0b11111110);
					SSeg_Display(hexRep[i-1]);

					//Check_Input2(privateKey,data);

					if (button_Pressed() == 1) break;	//if new data was sent exit.
				}//end while
			}

			else if (i == 2)
			{
				while(1){
					SSeg_En(0b11111101);
					SSeg_Display(hexRep[i-1]);
					usleep(5000);
					SSeg_En(0b11111110);
					SSeg_Display(hexRep[i-2]);
					usleep(5000);

					//Check_Input2(privateKey,data);

					if (button_Pressed() == 1) break;	//if new data was sent exit.

				}//end while
			}

			else if (i == 3)
			{
				while(1){
					SSeg_En(0b11111011);
					SSeg_Display(hexRep[i-1]);
					usleep(5000);
					SSeg_En(0b11111101);
					SSeg_Display(hexRep[i-2]);
					usleep(5000);
					SSeg_En(0b11111110);
					SSeg_Display(hexRep[i-3]);
					usleep(5000);

					//Check_Input2(privateKey,data);

					if (button_Pressed() == 1) break;	//if new data was sent exit.

				}//end while(1)
			}//end if

			else if (i == 4)
			{
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

					//Check_Input2(privateKey,data);

					if (button_Pressed() == 1) break;	//if new data was sent exit.
					else continue;
				}//end while(1)
			}


			break;
	}//end while()
}//end Display_Data()

void Generate_Keys(int max)
{
	while(1){
		prime1 = Generate_Prime(max);
		prime2 = Generate_Prime(max);
		int totient = (prime1 - 1)*(prime2 - 1);
		do{
			e = Generate_Prime(maxE); //Generate_Prime(max);
		}while (e == ((prime1 - 1)*(prime2 - 1)) || (e < 1));


		publicKey = prime1*prime2;
		//privateKey = (1 / totient) / (e * (1 - (1 / totient)));
		privateKey = modInverse(e,totient);
		if (   ((publicKey > 255)) && ((publicKey <= 1023) && (e <= 1023))   ) break;
		else continue;
		//privateKey = ((prime1 - 1)*(prime2 - 1)) / e;
	}

}//end generate_keys


void Dec_to_Hex(int n)
{
	i = 0;
	int temp = 0;

	while (n != 0)
	{
		temp = n % 16;

		if (temp < 10)
		{
			hexRep[i] = temp + 48;
			i++;
		}

		else
		{
			hexRep[i] = temp + 55;
			i++;
		}

		n= n/16;

	} // end while(n!=0)
}//end Dec_to_hex()

void Check_Input(int data)
{
	if (Read_Switches() == data)
	{
		if (i2 == 1)
		{
			SSeg_En(0b11101111);
			SSeg_Display(hexRep[i2-1]);
			usleep(5000);
		}

		else if (i2 == 2)
		{
			SSeg_En(0b11011111);
			SSeg_Display(hexRep[i2-1]);
			usleep(5000);
			SSeg_En(0b11101111);
			SSeg_Display(hexRep[i2-2]);
			usleep(5000);
		}

		else if (i2 == 3)
		{
			SSeg_En(0b10111111);
			SSeg_Display(hexRep[i2-1]);
			usleep(5000);
			SSeg_En(0b11011111);
			SSeg_Display(hexRep[i2-2]);
			usleep(5000);
			SSeg_En(0b11101111);
			SSeg_Display(hexRep[i2-3]);
			usleep(5000);
		}//end if

		else if (i2 == 4)
		{
			SSeg_En(0b01111111);
			SSeg_Display(hexRep[i2-1]);
			usleep(5000);
			SSeg_En(0b10111111);
			SSeg_Display(hexRep[i2-2]);
			usleep(5000);
			SSeg_En(0b11011111);
			SSeg_Display(hexRep[i2-3]);
			usleep(5000);
			SSeg_En(0b11101111);
			SSeg_Display(hexRep[i2-4]);
			usleep(5000);
		}

	}//end if(read)
}

int Sieve_Test(int n)
{

	prime = calloc(n+1, 1); //allocate memory for n+1 number of 1 byte elements

	//initialize all values to true or 1
	for (int i = 0; i < n+1; i++)
	{
		prime[i] = 1;
	}

	for (int p = 2; p*p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = 0;
		}
	}

	//check if the number passed in is divisible by any of these primes
	for (int p = 2; p <= n; p++)
		if (prime[p])
		{
			if (n == p);
			else if (n % p == 0)
			{

				return 0;
			}
		}

	free(prime);

	return 1;
}

int is_prime(int n)
{
	int i = 5;

	if (n <= 3)
		return n > 1;

	else if ((n % 2 == 0) | (n % 3 == 0))
	{
		return 0;
	}

	while (i*i <= n)
	{
		if ((n % i == 0) | (n % (i + 2) == 0))
		{
			return 0;
		}

		i += 6;
	}

	return 1;
}

int Generate_Prime(int max)
{
	int done = 0;
	int random = 0;
	//will keep generating numbers until it is prime within the range specified up to max input parameter
	do{
		//generate a random number
		//rand();

		random = random_num() % max;

		//Use a sieve algorithm to check if it is composite or not
		if (Sieve_Test(random) && is_prime(random)) done = 1;

	} while (!done);

	return random;
}

int Encrypt(int data)
{
	long int temp;
	temp = power(data,e);		//pow(data,e);

	//temp = temp % publicKey;
	double whole = 0;
	whole = ((double)temp)/((double)publicKey);
	double fraction = (double) (whole - ((long)whole));
	temp = fraction*publicKey;

	encryptedData = temp;
	return encryptedData;
}

long int power(int num, int pow)
{
	long int x = 1;
	for (int i = 0; i < pow; i++)
	{
		x = x*num;
	}

	return x;
}

void Dec_to_Hex2(int n)
{
	i2 = 0;
	int temp = 0;

	while (n != 0)
	{
		temp = n % 16;

		if (temp < 10)
		{
			hexRep2[i2] = temp + 48;
			i2++;
		}

		else
		{
			hexRep2[i2] = temp + 55;
			i2++;
		}

		n= n/16;

	} // end while(n!=0)
}//end Dec_to_hex()


unsigned random_num()
  {
	bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
	return lfsr =  (lfsr >> 1) | (bit << 15);
  }

int my_modulus(int a, int b)
{
	double whole = 0;
	whole = (double) a/b;
	double fraction = whole - ((long)whole);
	whole = fraction*b;
	return (int) whole;
}

void Check_Input2(int key,int data)
{

	int counter = 0;
	wrongFlag = 0;

		if (Read_Switches() == key)
		{
			int thousandsth = data/1000;
			int hundreds = (data%1000) / 100;
			int tenths = (data%100) / 10;
			int ones = (data%10);

			if (data < 10)
			{
				while(1){

					SSeg_En(0b11101111);
					SSeg_Display2(ones);
					usleep(500);
					counter++;
					if(counter >= 20000) break;
				}
			}

			else if (data >= 10 && data <= 99)
			{
				while(1){

				SSeg_En(0b11011111);
				SSeg_Display2(tenths);
				usleep(500);
				SSeg_En(0b11101111);
				SSeg_Display2(ones);
				usleep(500);
				counter++;
				if(counter >= 10000) break;
				}
			}

			else if (data >= 100 && data <= 999)
			{
				while(1)
				{
					SSeg_En(0b10111111);
					SSeg_Display2(hundreds);
					usleep(500);
					SSeg_En(0b11011111);
					SSeg_Display2(tenths);
					usleep(500);
					SSeg_En(0b11101111);
					SSeg_Display2(ones);
					usleep(500);
					counter++;
					if(counter >= 6666) break;
				}
			}//end if

			else if (data >= 1000)
			{
				while(1)
				{
					SSeg_En(0b01111111);
					SSeg_Display2(thousandsth);
					usleep(500);
					SSeg_En(0b10111111);
					SSeg_Display2(hundreds);
					usleep(500);
					SSeg_En(0b11011111);
					SSeg_Display2(tenths);
					usleep(500);
					SSeg_En(0b11101111);
					SSeg_Display2(ones);
					usleep(500);
					counter++;
					if(counter >= 5000) break;
				}
			}

			SSeg_En(0x00);
			SSeg_Display(0xFF);

		}//end if(read)
		else wrongFlag = 1;


}//end check_input2();


void SSeg_Display2(int value)

{
	switch (value)
	{
		case 0:
				value = 0b11000000;
				break;
		case 1:
				value = 0b11111001;
				break;
		case 2:
				value = 0b10100100;
				break;
		case 3:
				value = 0b10110000;
				break;
		case 4:
				value = 0b10011001;
				break;
		case 5:
				value = 0b10010010;
				break;
		case 6:
				value = 0b10000010;
				break;
		case 7:
				value = 0b11111000;
				break;

		case 8:
				value = 0b10000000;
				break;

		case 9:
				value = 0b10011000;
				break;

		default:
				value =  0b11000000;
				break;
	}//end switch

	XGpio_DiscreteWrite(&Gpio_SSEG, SSEG_CHANNEL, value);
}//end Sseg_Display2();


int Decrypt(char encryptedData)
{
	int finalData = (encryptedData^privateKey) % publicKey;
	return finalData;
}

int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

int button_Pressed()
{
	int temp  = XGpio_DiscreteRead(&Gpio_Password, PASS_CONFIRM_CHANNEL);
	return temp;
}




