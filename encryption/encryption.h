#pragma once
#include <stdio.h>

void exitError(char** messege);
FILE* openFile(char** fileName);
FILE* creatingFile(char** fileName);
void encryptingFile(FILE* f_in, int* key_numbers, int lengthKey, FILE* f_out);
int keyEncoding(char* key_string, int** p_key_numbers);

