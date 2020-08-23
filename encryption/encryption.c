#include <stdio.h>

void openFileToEncryption()
{
	FILE* f_in;
	fopen_s(&f_in, "try.txt", "r+");
	if (f_in == NULL)
	{
		printf("File not found\n");
	}
}


void main() {
	openFileToEncryption();

	printf("test");
}