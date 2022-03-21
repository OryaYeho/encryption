﻿#include "des.h"
#include <io.h>

void encrypt_des(FILE* fd_in, FILE* fd_out, char* key_str) {
	// Input:	fd_in - A file that needs to encryption.
	//			fd_out - An encrypted file.
	//			key - A key to encrypting.
	//			lengthKey - Length of key.
	// Do:	Creating an encrypted file.

	int lengthKey = strlen(key);
	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	DesContext key;		 // <<<<<<<
	key = (uint32_t)key_str[0] << 24 |
		(uint32_t)key_str[1] << 16 |
		(uint32_t)key_str[2] << 8 |
		(uint32_t)key_str[3];

	while ((sumByteReaded = fread(&buffer, BUFFER_SIZE, 1, fd_in)) != 0)
	{
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		desEncryptBlock(&key, &buffer, &buffer)
		/*buffer += key[keyIndex];
		buffer = buffer % 256;*/

		if (fwrite(&buffer, BUFFER_SIZE, 1, fd_out) == -1)
		{
			exitError("Error writing file");
		}

		/*keyIndex++;
		keyIndex %= lengthKey;*/
	}


}

void decrypt_des(FILE* fd_in, FILE* fd_out, char* key_str)
{
	// Input:	fd_in - A file that needs to decipher.
	//			fd_out - A decoded file.
	//			key - A key to encrypting.
	//			lengthKey - Length of key.
	// Do:	Makes decoding to file..

	int lengthKey = strlen(key);
	char buffer;
	int sumByteReaded;
	int keyIndex = 0;

	DesContext key;		 // <<<<<<<
	key = (uint32_t)key_str[0] << 24 |
		(uint32_t)key_str[1] << 16 |
		(uint32_t)key_str[2] << 8 |
		(uint32_t)key_str[3];

	while ((sumByteReaded = fread(&buffer, BUFFER_SIZE, 1, fd_in)) != 0)
	{
		if (sumByteReaded == -1)
		{
			exitError("Error reading file");
		}

		desDecryptBlock(&key, &buffer, &buffer)
		/*buffer -= key[keyIndex];
		if (buffer < 0)
		{
			buffer += 256;
		}*/

		if (fwrite(&buffer, BUFFER_SIZE, 1, fd_out) == -1)
		{
			exitError("Error writing file");
		}

		/*keyIndex++;
		keyIndex %= lengthKey;*/
	}
}