#include <stdio.h>
#include <stdint.h>

#include "sha3.h"
#include "encryption.h"
#include "logIn.h"
#include "my_aes.h"

#define TEMP_NAME "tempFile"

void crypt(void (*action_fun)(FILE*, FILE*, char*), char* message);


void main(int argc, char* argv[]) {
	char action;

	//logIn();

	printf("What are you want to do:\n");
	printf(" 1 - To do encryption to file.\n");
	printf(" 2 - To do decryption to file.\n");
	action = getchar();

	switch (action)
	{
	case '1':
		crypt(encryptingFile, "Encryption has been performed.");
		break;
	case '2':
		crypt(decryptingFile, "The decoding was performed.");
		break;
	case '3':
		crypt(encrypt_aes, "Encryption has been performed.");
		break;
	/*case '4':
		crypt(decrypt_des, "The decoding was performed.");
		break;*/
	default:
		exitError("Wrong action!");
	}
	
	return 0;
}

void crypt(void (*action_fun)(FILE*, FILE*, char*), char* message) {
	// input: pointer to function to action and message to print when that action was performed.
	// do: getting filename and key from the user and call to function of action with this parameters.


	FILE* fd_in;
	FILE* fd_out = creatingFile(TEMP_NAME);
	char filename[20];
	char key[512];

	printf("\nEnter file name: ");
	scanf_s("%s", filename, 20);
	fd_in = openFile(filename);

	printf("\nEnter key: ");
	scanf_s("%s", key, 512);
	if (strlen(key) < 8)
		exitError("The key is too short!");


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