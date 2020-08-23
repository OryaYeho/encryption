#include <stdio.h>

void openFileToEncryption(char** fileName)
{
	FILE* f_in;
	char ch;

	fopen_s(&f_in, fileName, "r+");
	if (f_in == NULL)
	{
		printf("File not found\n");
	}
	else
	{
		ch = fgetc(f_in);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(f_in);
		}
		printf("\n");
	}
}


void main() {
	openFileToEncryption("try.txt");

	printf("test");
}