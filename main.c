#include <stdio.h>
#include <stdint.h>

#include "sha3.h"
#include "encryption.h"
#include "logIn.h"

#define TEMP_NAME "tempFile"

void main(int argc, char* argv[]) {
	FILE* fd_in;
	FILE* fd_out;

	char action;

	char filename[20];
	char* key = "orya";
	int actionFlag;

	//logIn();

	printf("What are you want to do:\n");
	printf(" 1 - To do encryption to file.\n");
	printf(" 2 - To do decryption to file.\n");
	action = getchar();

	printf("\nEnter file name: ");
	//scanf_s("%s", filename);
	scanf_s("%s", filename,20);

	switch (action)
	{
	case '1':
		fd_in = openFile(filename);
		fd_out = creatingFile(TEMP_NAME);
		encryptingFile(fd_in, fd_out, key);
		printf("Encryption has been performed.\n");
		break;
	case '2':
		fd_in = openFile(filename);
		fd_out = creatingFile(TEMP_NAME);
		decryptingFile(fd_in, fd_out, key);
		printf("The decoding was performed.\n");
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