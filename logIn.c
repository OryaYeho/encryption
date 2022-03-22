#include "logIn.h"

extern const int ORIGINAL_PASSWORD[LENGTH_ORIGINAL_PASSWORD] = { 96,170,89,91,247,41,225,230,252,227,17,30,136,147,
	100,36,168,164,234,104,211,51,97,129,131,150,90,10,57,229,87,84 };


// input: a sequence of hash code.
// output: 0 - for wrong password.
int checkPassword(uint8_t* hashPassword)
{
	for (int i = 0; i < LENGTH_ORIGINAL_PASSWORD; i++)
	{
		if (ORIGINAL_PASSWORD[i] != ((int)(hashPassword[i])))
		{
			return 0;
		}
	}
	return 1;
}


void logIn() {

	char password[20];
	sha3_context contextPassword;
	uint8_t* hashPassword;

	printf("Enter password to log in: ");
	gets(password);

	sha3_Init256(&contextPassword);
	sha3_SetFlags(&contextPassword, SHA3_FLAGS_KECCAK);
	sha3_Update(&contextPassword, password, strlen(password));
	hashPassword = sha3_Finalize(&contextPassword);

	if (checkPassword(hashPassword) == 0)
		exitError("Wrong password!");
	else
		printf("Logged in!\n\n");
}