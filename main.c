#include <stdio.h>
#include <stdint.h>

#include "sha3.h"
#include "encryption.h"
#include "logIn.h"

#define TEMP_NAME "tempFile"

void crypt(void (*action_fun)(FILE*, FILE*,char*), char* key, char* message) {
	FILE* fd_in;
	FILE* fd_out = creatingFile(TEMP_NAME);
	char filename[20];

	printf("\nEnter file name: ");
	scanf_s("%s", filename, 20);

	fd_in = openFile(filename);

	action_fun(fd_in, fd_out, key);
	puts(message);

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
}

void main(int argc, char* argv[]) {

	char action;
	char* key = "orya";



	//logIn();

	printf("What are you want to do:\n");
	printf(" 1 - To do encryption to file.\n");
	printf(" 2 - To do decryption to file.\n");
	action = getchar();

	

	switch (action)
	{
	case '1':
		/*fd_in = openFile(filename);
		fd_out = creatingFile(TEMP_NAME);
		encryptingFile(fd_in, fd_out, key);
		printf("Encryption has been performed.\n");*/
		//message = "Encryption has been performed.";
		crypt(encryptingFile, key, "Encryption has been performed.");
		break;
	case '2':
		/*fd_in = openFile(filename);
		fd_out = creatingFile(TEMP_NAME);
		decryptingFile(fd_in, fd_out, key);
		printf("The decoding was performed.\n");*/
		crypt(decryptingFile, key, "The decoding was performed.");
		break;
	default:
		exitError("Wrong action!");
	}


	/*if (deleteOriginalFile(fd_in, filename) != 0)
	{
		printf("Unable to delete the original file.\n");
		printf("The encrypted file is named '");
		printf(TEMP_NAME);
		printf("'.\n");
	}
	else
	{
		renameEncryptedFile(fd_out, TEMP_NAME, filename);
	}*/
	
	return 0;
}