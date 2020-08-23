#include <stdio.h>

void exitError(char** messege)
{
	printf(messege);
	printf("/n");
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

int* keyEncoding(char** key_string)
{
	if (strlen(key_string) < 8) {
		exitError("Key less than 8 characters.");
	}
}


void main() {
	FILE *f_in = openFileToEncryption("try.txt");

	encryptingFile(f_in, "key");
	printf("Amazing");

	
}