#include <stdio.h>

void exitError(char** messege)
{
	printf(messege);
	printf("\n");
	getchar();
	exit(1);
}

FILE* openFileToEncryption(char** fileName)
{
	FILE* file;
	
	fopen_s(&file, fileName, "r+");
	if (file == NULL)
	{
		exitError("File not found.");
	}
	
	return(file);
}

void encryptingFile(FILE* file, char** key)
{
	char ch = fgetc(file);

	while (ch != EOF)
	{
		printf("%c", ch);
		ch = fgetc(file);
	}
	printf("\n");
}

int* keyEncoding(char** key_string, int** key_numbers)
{
	// Input: key_string - String of key.
	// Output: Array of number. The numbers is values ​​of the letters (A = 1).
	int lengthKey = strlen(key_string);
	int i;
	char ch;

	if (lengthKey < 8) {
		exitError("Key less than 8 characters.");
	}

	*key_numbers = malloc(lengthKey * sizeof(int));

	for (i = 0; i < lengthKey; i++)
	{
		ch = *key_string + i;
		*(*key_numbers + i) = ch - 'A' + 1;
	}
	
	return lengthKey;
}


void main() {
	FILE *f_in = openFileToEncryption("try.txt");
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