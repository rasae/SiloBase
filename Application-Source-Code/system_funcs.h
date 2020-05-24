/*
 * system_funcs.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Rafed
 */


#ifndef SRC_SYSTEM_FUNCS_H_
#define SRC_SYSTEM_FUNCS_H_

#include "system_init.h"

/*------------GLOBAL VARIABLES FOR KEYS-----------------*/
int publicKey;	//publickey = prime1*prime2	//not shown to user
int privateKey;	//privkey = (prime1 - 1)*(prime2-1) / e  -----> shown to user, can't be bigger than 65,535_decimal
int prime1, prime2;
int e;
int rawData;
int encryptedData;
int decryptedData;
int i;


char hexRep[10];
char hexRep2[10];

int wrongFlag;



/*----------FUNCTION PROTOTYPES---------------*/
int modInverse(int a, int m);

void SSeg_Display2(int value);

void Check_Input2(int,int);

void display_private_keys(int);

int Read_Switches();

void SSeg_Display(char);

void SSeg_En(int);

void Send_Byte(char);

char Receive_Byte();

void Display_Data(int data);

void Generate_Keys();

int Generate_Prime(int);

void Pic_Toggle(int n);


void Dec_to_Hex(int);

void Check_Input(int);

int Sieve_Test(int n);

int is_prime(int n);

int Encrypt(int data);

void Dec_to_Hex2(int);

unsigned random_num();

int my_modulus(int a, int b);

long int power(int num, int pow);

int Decrypt(char);

int button_Pressed();


#endif /* SRC_SYSTEM_FUNCS_H_ */
