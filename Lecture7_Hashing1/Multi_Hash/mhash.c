#include "mhash.h"

#include <stdio.h>
#include <stdlib.h>

extern int Multi_Hash(int key, int num_slots, int power_2);


int Multi_Hash(int key, int num_slots, int power_2){
    unsigned int A = 0b10000001000010001000010001011001; // an odd integer between 2^31 to 2^32
    unsigned int temp = (A*key) % 4294967296; // A*key mod (2^32)
    unsigned int res = temp >> (32-power_2);  // right shift

    return res;
}
