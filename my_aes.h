#include <stdio.h>
#include <io.h>
//#include "aes.h"

void encrypt_aes(FILE* fd_in, FILE* fd_out, char* key_str);
void decrypt_des(FILE* fd_in, FILE* fd_out, char* key_str);