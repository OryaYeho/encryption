#include <stdio.h>
#include "encryption.h"

void main() {
	FILE *f_in = openFile("try.txt");
	char** key_string = "ABCDEFGH";
	int* key_numbers;
	int lengthKey,i;

	encryptingFile(f_in, key_string);
	lengthKey = keyEncoding(key_string, &key_numbers);

	for (i = 0; i < lengthKey; i++) {
		printf("%d ", key_numbers[i]);
	}

	printf("\nAmazing");
	free(key_numbers);

}