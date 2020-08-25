#include <stdio.h>
#include "encryption.h"

#define TEMP_NAME "tempFile.txt"


void main(int argc, char* argv[]) {
	FILE* f_in;
	FILE* f_out;

	char* password = argv[1];
	char* filename = argv[2];
	char* key_string = argv[3];
	int actionFlag = atoi(argv[4]);

	int* key_numbers;
	int lengthKey,i;

	f_in = openFile(filename);
	f_out = creatingFile(TEMP_NAME);

	lengthKey = keyEncoding(key_string, &key_numbers);

	if (actionFlag == 1)
	{
		encryptingFile(f_in, key_numbers, lengthKey, f_out);
	}
	else
	{
		printf("Decoding operation\n");
	}

	if (deleteOriginalFile(f_in, filename) != 0)
	{
		printf("Unable to delete the original file.\n");
		printf("The encrypted file is named '");
		printf(TEMP_NAME);
		printf("'.\n");
	}
	else
	{
		renameEncryptedFile(f_out, TEMP_NAME, filename);
	}



	printf("\nnum of argument is: %d.\n",argc);
	printf("password is: %s\n", argv[1]);
	printf("filename is: %s\n", argv[2]);
	printf("key is: %s\n", argv[3]);
	printf("flag is: %s\n", argv[4]);


	free(key_numbers);
	return 0;
}