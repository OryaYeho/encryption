#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "sha3.h"
#include "encryption.h"
#include "password.h"


#define TEMP_NAME "tempFile"


void main(int argc, char* argv[]) {
	FILE* fd_in;
	FILE* fd_out;

	char* password_string = argv[1];
	char* filename = argv[2];
	char* key_string = argv[3];
	int actionFlag = atoi(argv[4]);

	int* key_numbers;
	int lengthKey,i;

	//--------- password ---------
	sha3_context contextPassword;
	uint8_t* hashPassword;
	
	
	sha3_Init256(&contextPassword);
	sha3_SetFlags(&contextPassword, SHA3_FLAGS_KECCAK);
	sha3_Update(&contextPassword, password_string, strlen(password_string));
	hashPassword = sha3_Finalize(&contextPassword);

	if (checkingCorrectnessPassword(hashPassword) == 0)
	{
		exitError("Wrong password!");
	}

	fd_in = openFile2(filename);
	fd_out = creatingFile2(TEMP_NAME);

	lengthKey = keyEncoding(key_string, &key_numbers);

	if (actionFlag == 1)
	{
		encryptingFile2(fd_in, fd_out, key_numbers, lengthKey);
		printf("Encryption has been performed.\n");
	}
	else
	{
		decipheringFile2(fd_in, fd_out, key_numbers, lengthKey);
		printf("The decoding was performed.\n");
	}

	if (deleteOriginalFile(fd_in, filename) != 0)
	{
		printf("Unable to delete the original file.\n");
		printf("The encrypted file is named '");
		printf(TEMP_NAME);
		printf("'.\n");
	}
	else
	{
		renameEncryptedFile(fd_out, TEMP_NAME, filename);
	}
	
	free(key_numbers);
	return 0;
}