#pragma once
#include <stdio.h>

void exitError(char** messege);
FILE* openFile(char** fileName);
FILE* creatingFile(char** fileName);
void encryptingFile(FILE* f_in, int* key_numbers, int lengthKey, FILE* f_out);
void decipheringFile(FILE* f_in, int* key_numbers, int lengthKey, FILE* f_out);
int keyEncoding(char* key_string, int** p_key_numbers);
int deleteOriginalFile(FILE* file, const char* filename);
int renameEncryptedFile(FILE* file, const char* oldname, const char* newname);

int openFileIn(char** fileName);
int creatFileOut(char** fileName);
void encryptingFile1(int const fd_in, int const fd_out, int* key_numbers, int lengthKey);
void decipheringFile1(int const fd_in, int const fd_out, int* key_numbers, int lengthKey);
int deleteOriginalFile1(int fd, const char* filename);

FILE* openFile2(char** fileName);
FILE* creatingFile2(char** fileName);
void encryptingFile2(int const fd_in, int const fd_out, int* key_numbers, int lengthKey);
void decipheringFile2(int const fd_in, int const fd_out, int* key_numbers, int lengthKey);

