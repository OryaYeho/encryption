#include "encryption.h"
#include <io.h>

#define BUFFER_SIZE 1

void exitError(char** messege)
{
	printf(messege);
	printf("\n");
	getch();
	exit(1);
}

FILE* openFile(char** fileName)
{
	// Input: File name to open.
	// Do: Opens the file if possible. Otherwise, sends an error message and exits.

	FILE* file;

	fopen_s(&file, fileName, "rb");
	if (file == NULL)
	{
		exitError("File not found.");
	}

	return(file);
}

FILE* creatingFile(char** fileName)
{
	// Input: File name to creat.
	// Do: Creating the file if possible. Otherwise, sends an error message and exits.

	FILE* file;

	fopen_s(&file, fileName, "wb");
	if (file == NULL)
	{
		exitError("Cannot create a file.");
	}

	return(file);
}

int keyEncoding(char* key_string, int** p_key_numbers)
{
	// Input:	key_string - string of key.
	//			p_key_numbers - Pointer to array of values ​​of the letters (A = 1).
	// Return: Length of key.
	int lengthKey = strlen(key_string);
	int i;
	char ch;
	int* key_numbers;

	if (lengthKey < 8) {
		exitError("Key less than 8 characters.");
	}

	*p_key_numbers = malloc(lengthKey * sizeof(int));

	for (i = 0; i < lengthKey; i++)
	{
		ch = key_string[i];	
		//(*p_key_numbers)[i] = ch - 'A' + 1;
		(*p_key_numbers)[i] = ch;
	}
	return lengthKey;
}

//void encryptingFile(FILE* fd_in, FILE* fd_out, int* key, int lengthKey) {
void encryptingFile(FILE* fd_in, FILE* fd_out, char* key, int lengthKey1) {
	// Input:	fd_in - A file that needs to encryption.
	//			fd_out - An encrypted file.
	//			key - A key to encrypting.
	//			lengthKey - Length of key.
	// Do:	Creating an encrypted file.

	int lengthKey = strlen(key);
	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	while ((sumByteReaded = fread(&buffer, BUFFER_SIZE, 1, fd_in)) != 0)
	{
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		buffer += key[keyIndex];
		buffer = buffer % 256;

		if (fwrite(&buffer, BUFFER_SIZE, 1, fd_out) == -1)
		{
			exitError("Error writing file");
		}

		keyIndex++;
		keyIndex %= lengthKey;
	}
}

//void decipheringFile(FILE* fd_in, FILE* fd_out, int* key, int lengthKey)
void decipheringFile(FILE* fd_in, FILE* fd_out, char* key, int lengthKey1)
{
	// Input:	fd_in - A file that needs to decipher.
	//			fd_out - A decoded file.
	//			key - A key to encrypting.
	//			lengthKey - Length of key.
	// Do:	Creating an encrypted file.

	int lengthKey = strlen(key);
	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	while ((sumByteReaded = fread(&buffer, BUFFER_SIZE, 1, fd_in)) != 0)
	{
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		buffer -= key[keyIndex];
		if (buffer < 0)
		{
			buffer += 256;
		}

		if (fwrite(&buffer, BUFFER_SIZE, 1, fd_out) == -1)
		{
			exitError("Error writing file");
		}

		keyIndex++;
		keyIndex %= lengthKey;
	}
}

int deleteOriginalFile(FILE* file, const char* filename)
{
	if (fclose(file) != 0)
	{
		printf("A source file is not closed and therefore will not be deleted.\n");
		return -1;
	}

	return remove(filename);
}

int renameEncryptedFile(FILE* file, const char* oldname, const char* newname)
{
	if (fclose(file) != 0)
	{
		printf("A encrypted  file is not closed.\n");
	}

	return rename(oldname, newname);
}
