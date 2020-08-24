#pragma once
#include <stdio.h>

void exitError(char** messege);
FILE* openFile(char** fileName);
void encryptingFile(FILE* file, char** key);
int* keyEncoding(char** key_string, int** key_numbers);

