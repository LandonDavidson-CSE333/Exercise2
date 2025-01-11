// Copyright 2025 Landon Davidson
// Landon Davidson
// landond@uw.edu

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

// Prints the bytes of the given value as hexadecimal to terminal
void PrintBytes(void*, int);

int main(int argc, char **argv) {
    char     char_val = '0';
    int32_t  int_val = 1;
    float    float_val = 1.0;
    double   double_val  = 1.0;

    typedef struct {
        char     char_val;
        int32_t  int_val;
        float    float_val;
        double   double_val;
    } Ex2Struct;

    Ex2Struct struct_val = { '0', 1, 1.0, 1.0 };

    PrintBytes(&char_val, sizeof(char));
    PrintBytes(&int_val, sizeof(int32_t));
    PrintBytes(&float_val, sizeof(float));
    PrintBytes(&double_val, sizeof(double));
    PrintBytes(&struct_val, sizeof(struct_val));

    return EXIT_SUCCESS;
}

void PrintBytes(void* p, int size) {
    // Print leading text for each entry, listing the data size in bytes and address
    printf("The %d bytes starting at %p are: ", size, p);
    for (int i = 0; i < size; i++) {
        // Print the two digit hexadecimal value of each byte with padding zeroes followed by a space,
        // moving one byte each loop
        printf("%02x ", *((uint8_t*) p) + i); //
    }
    // Print a newline for the next entry
    printf("\n");
}
