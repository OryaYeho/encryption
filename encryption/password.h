#include <inttypes.h>
#include "sha3.h"
#include <string.h>
#include "encryption.h"

extern const int ORIGINAL_PASSWORD[32];

int checkingCorrectnessPassword(uint8_t* hashPassword);

uint8_t* create_sha3(char* password_string, int lengthPassword);