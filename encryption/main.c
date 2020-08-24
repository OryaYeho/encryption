#include <stdio.h>
#include "encryption.h"

#define FILE_NAME "try.txt"


void main() {
	FILE* f_in;
	FILE* f_out;
	char* key_string = "AAAAAAAA";
	int* key_numbers;
	int lengthKey,i;

	f_in = openFile(FILE_NAME);
	f_out = creatingFile("tempFile.txt");

	lengthKey = keyEncoding(key_string, &key_numbers);
	encryptingFile(f_in, key_numbers, lengthKey, f_out);

	/*
	for (i = 0; i < lengthKey; i++) {
		printf("%d ", key_numbers[i]);
	}
	*/

	printf("\nAmazing");
	free(key_numbers);
	return 0;
}