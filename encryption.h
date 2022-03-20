#include <stdio.h>

void exitError(char** messege);
FILE* openFile(char** fileName);
FILE* creatingFile(char** fileName);
void encryptingFile(FILE* fd_in, FILE* fd_out, char* key);
void decryptingFile(FILE* fd_in, FILE* fd_out, char* key);
int deleteOriginalFile(FILE* file, const char* filename);
int renameEncryptedFile(FILE* file, const char* oldname, const char* newname);