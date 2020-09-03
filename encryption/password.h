#include <inttypes.h>
#include "sha3.h"

#define LENGTH_ORIGINAL_PASSWORD 32

extern const int ORIGINAL_PASSWORD[LENGTH_ORIGINAL_PASSWORD];

int checkingCorrectnessPassword(uint8_t* hashPassword);

uint8_t* create_sha3(char* password_string, int lengthPassword); // not using!!