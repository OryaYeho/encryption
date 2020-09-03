#include <stdio.h>

void exitError(char** messege);
FILE* openFile(char** fileName);
FILE* creatingFile(char** fileName);
int keyEncoding(char* key_string, int** p_key_numbers);
void encryptingFile(FILE* fd_in, FILE* fd_out, int* key_numbers, int lengthKey);
void decipheringFile(FILE* fd_in, FILE* fd_out, int* key_numbers, int lengthKey);
int deleteOriginalFile(FILE* file, const char* filename);
int renameEncryptedFile(FILE* file, const char* oldname, const char* newname);