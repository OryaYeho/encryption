#include "encryption.h"
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include < fcntl.h >
#include < wchar.h >

#define _SCL_SECURE_NO_WARNINGS

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
	// Do: Opens the file if possible. Otherwise, sends an error message.

	FILE* file;

	fopen_s(&file, fileName, "r");
	if (file == NULL)
	{
		exitError("File not found.");
	}

	return(file);
}

FILE* creatingFile(char** fileName)
{
	// Input: File name to creat.
	// Do: Creating the file if possible. Otherwise, sends an error message.

	FILE* file;

	fopen_s(&file, fileName, "w");
	if (file == NULL)
	{
		exitError("Cannot create a file.");
	}

	return(file);
}

int keyEncoding(char* key_string, int** p_key_numbers)
{
	// Input:	key_string - Pointer to string of key.
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
		(*p_key_numbers)[i] = ch - 'A' + 1;
	}
	return lengthKey;
}

void encryptingFile(FILE* f_in, int* key_numbers, int lengthKey, FILE* f_out)
{
	// Input:	f_in - A file that needs to encryption.
	//			key_numbers - A key to encrypting.
	//			lengthKey - Length of key.
	//			f_out - An encrypted file.
	// Do:	Creating an encrypted file.

	char ch = fgetc(f_in);
	int keyIndex = 0;

	while (ch != EOF)
	{
		ch += key_numbers[keyIndex];
		ch = ch % 256;
		fputc(ch, f_out);

		keyIndex++;
		keyIndex %= lengthKey;

		ch = fgetc(f_in);
	}
}

void decipheringFile(FILE* f_in, int* key_numbers, int lengthKey, FILE* f_out)
{
	// Input:	f_in - A file that needs to decipher.
	//			key_numbers - A key to encrypting.
	//			lengthKey - Length of key.
	//			f_out - A decoded file.
	// Do:	Creating an encrypted file.

	char ch = fgetc(f_in);
	int keyIndex = 0;

	while (ch != EOF)
	{
		
		ch -= key_numbers[keyIndex];
		if (ch < 0)
		{
			ch += 256;
		}

		fputc(ch, f_out);

		keyIndex++;
		keyIndex %= lengthKey;
		
		ch = fgetc(f_in);
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

// ************************
int openFileIn(char** filename)
{
	// Input: File name to open.
	// Do: Opens the file if possible. Otherwise, sends an error message.
	int pfh;

	_sopen_s(&pfh, filename, _O_RDONLY, _SH_DENYNO, _S_IREAD | _S_IWRITE);

	if (pfh == -1)
	{
		exitError("File not found.");
	}

	return(pfh);
}

int creatFileOut(char** filename)
{
	// Input: File name to creat.
	// Do: Creating the file if possible. Otherwise, sends an error message.

	int pfh;

	_sopen_s(&pfh, filename, _O_CREAT, _SH_DENYRD, _S_IWRITE);

	if (pfh == -1)
	{
		exitError("Cannot create a file.");
	}

	return(pfh);
}

void encryptingFile1(int const fd_in, int const fd_out, int* key_numbers, int lengthKey) {
	// Input:	f_in - A file that needs to encryption.
	//			key_numbers - A key to encrypting.
	//			lengthKey - Length of key.
	//			f_out - An encrypted file.
	// Do:	Creating an encrypted file.

	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	while ((sumByteReaded = _read(fd_in, &buffer, BUFFER_SIZE)) != 0)
	{
		printf("&c",buffer);
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		buffer += key_numbers[keyIndex];
		buffer = buffer % 256;
		
		if (_write(fd_out, &buffer, BUFFER_SIZE) == -1)
		{
			exitError("Error writing file");
		}
		

		keyIndex++;
		keyIndex %= lengthKey;
	}
}

void decipheringFile1(int const fd_in, int const fd_out, int* key_numbers, int lengthKey)
{
	// Input:	f_in - A file that needs to decipher.
	//			key_numbers - A key to encrypting.
	//			lengthKey - Length of key.
	//			f_out - A decoded file.
	// Do:	Creating an encrypted file.

	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	while ((sumByteReaded = _read(fd_in, &buffer, BUFFER_SIZE)) != 0)
	{
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		buffer -= key_numbers[keyIndex];
		if (buffer < 0)
		{
			buffer += 256;
		}

		if (_write(fd_out, buffer, BUFFER_SIZE) == -1)
		{
			exitError("Error writing file");
		}

		keyIndex++;
		keyIndex %= lengthKey;
	}
}

int deleteOriginalFile1(int fd, const char* filename)
{
	if (_close(fd) != 0)
	{
		printf("A source file is not closed and therefore will not be deleted.\n");
		return -1;
	}

	return remove(filename);
}

int renameEncryptedFile1(int fd, const char* oldname, const char* newname)
{
	if (_close(fd) != 0)
	{
		printf("A encrypted  file is not closed.\n");
	}

	return rename(oldname, newname);
}



FILE* openFile2(char** fileName)
{
	// Input: File name to open.
	// Do: Opens the file if possible. Otherwise, sends an error message.

	FILE* file;

	fopen_s(&file, fileName, "rb");
	if (file == NULL)
	{
		exitError("File not found.");
	}

	return(file);
}

FILE* creatingFile2(char** fileName)
{
	// Input: File name to creat.
	// Do: Creating the file if possible. Otherwise, sends an error message.

	FILE* file;

	fopen_s(&file, fileName, "wb");
	if (file == NULL)
	{
		exitError("Cannot create a file.");
	}

	return(file);
}

void encryptingFile2(FILE* fd_in, FILE* fd_out, int* key_numbers, int lengthKey) {
	// Input:	f_in - A file that needs to encryption.
	//			key_numbers - A key to encrypting.
	//			lengthKey - Length of key.
	//			f_out - An encrypted file.
	// Do:	Creating an encrypted file.

	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	while ((sumByteReaded = fread(&buffer, BUFFER_SIZE, 1, fd_in)) != 0)
	{
		//printf("&c", buffer);
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		buffer += key_numbers[keyIndex];
		buffer = buffer % 256;

		if (fwrite(&buffer, BUFFER_SIZE, 1, fd_out) == -1)
		{
			exitError("Error writing file");
		}


		keyIndex++;
		keyIndex %= lengthKey;
	}
}

void decipheringFile2(FILE* fd_in, FILE* fd_out, int* key_numbers, int lengthKey)
{
	// Input:	f_in - A file that needs to decipher.
	//			key_numbers - A key to encrypting.
	//			lengthKey - Length of key.
	//			f_out - A decoded file.
	// Do:	Creating an encrypted file.

	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	while ((sumByteReaded = fread(&buffer, BUFFER_SIZE, 1, fd_in)) != 0)
	{
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		buffer -= key_numbers[keyIndex];
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

