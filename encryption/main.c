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
	//int fd_in, fd_out;


	char* password_string = argv[1];
	char* filename = argv[2];
	char* key_string = argv[3];
	int actionFlag = atoi(argv[4]);

	int* key_numbers;
	int lengthKey,i;

	//--------- password ---------
	sha3_context contextPassword;
	uint8_t* hashPassword;
	

	//hashPassword = create_sha3(password_string, strlen(password_string));

	
	sha3_Init256(&contextPassword);
	sha3_SetFlags(&contextPassword, SHA3_FLAGS_KECCAK);
	sha3_Update(&contextPassword, password_string, strlen(password_string));
	hashPassword = sha3_Finalize(&contextPassword);

	if (checkingCorrectnessPassword(hashPassword) == 0)
	{
		exitError("Wrong password!");
	}
	
	
	// printf("password: %s\n",password_string);
	// printf("quality:  0x ");

	/*
	for (i = 0; i < 32; i++)
	{
		if (ORIGINAL_PASSWORD[i] != ((int)(hashPassword[i])))
		{
			printf("false\n");
		}
		
		printf("%d," ,((int)hashPassword[i]));
	}
	printf("\n");
	*/

	//----------------------------
	/*
	fd_in = openFileIn(filename);
	fd_out = creatFileOut(TEMP_NAME);

	lengthKey = keyEncoding(key_string, &key_numbers);

	if (actionFlag == 1)
	{
		encryptingFile1(fd_in, fd_out, key_numbers, lengthKey);
		printf("Encryption has been performed.\n");
	}
	else
	{
		decipheringFile1(fd_in, fd_out, key_numbers, lengthKey);
		printf("The decoding was performed.\n");
	}

	
	if (deleteOriginalFile1(fd_in, filename) != 0)
	{
		printf("Unable to delete the original file.\n");
		printf("The encrypted file is named '");
		printf(TEMP_NAME);
		printf("'.\n");
	}
	else
	{
		renameEncryptedFile1(fd_out, TEMP_NAME, filename);
	}
	*/



	fd_in = openFile2(filename);
	fd_out = creatingFile2(TEMP_NAME);

	lengthKey = keyEncoding(key_string, &key_numbers);

	if (actionFlag == 1)
	{
		//encryptingFile(f_in, key_numbers, lengthKey, f_out);
		encryptingFile2(fd_in, fd_out, key_numbers, lengthKey);
		printf("Encryption has been performed.\n");
	}
	else
	{
		//decipheringFile(f_in, key_numbers, lengthKey, f_out);
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
	

	/*
	printf("\nnum of argument is: %d.\n",argc);
	printf("password is: %s\n", argv[1]);
	printf("filename is: %s\n", argv[2]);
	printf("key is: %s\n", argv[3]);
	printf("flag is: %s\n", argv[4]);
	*/

	
	free(key_numbers);
	return 0;
}