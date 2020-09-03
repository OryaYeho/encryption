#include "password.h"

#include <stdio.h>
#include <stdint.h>

#include "sha3.h"
#include "encryption.h"


extern const int ORIGINAL_PASSWORD[LENGTH_ORIGINAL_PASSWORD] = { 96,170,89,91,247,41,225,230,252,227,17,30,136,147,100,36,168,164,234,104,211,51,97,129,131,150,90,10,57,229,87,84 };

uint8_t* create_sha3(char* password_string, int lengthPassword)
{
	// not using!!!!!!!!!!
	sha3_context contextPassword;
	uint8_t* hashPassword1;
	int l = strlen(password_string);

	sha3_Init256(&contextPassword);
	sha3_SetFlags(&contextPassword, SHA3_FLAGS_KECCAK);
	sha3_Update(&contextPassword, password_string, l);
	hashPassword1 = sha3_Finalize(&contextPassword);
	return hashPassword1;
}

int checkingCorrectnessPassword(uint8_t* hashPassword)
{
	int i;

	for (i = 0; i < LENGTH_ORIGINAL_PASSWORD; i++)
	{
		if (ORIGINAL_PASSWORD[i] != ((int)(hashPassword[i])))
		{
			return 0;
		}
	}

	return 1;
}