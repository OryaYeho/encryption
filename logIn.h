#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

//#include "encryption.h"
#include "sha3.h"

#define LENGTH_ORIGINAL_PASSWORD 32

extern const int ORIGINAL_PASSWORD[LENGTH_ORIGINAL_PASSWORD];

int checkPassword(uint8_t* hashPassword);

//uint8_t* create_sha3(char* password_string, int lengthPassword); // not using!!