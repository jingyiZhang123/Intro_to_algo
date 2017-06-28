#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mhash.h"

// do NOT pick the hash size with a small divisor. prime number is preferred
// and not too close to the power of 2 or 10
#define HASH_SIZE 128

void Hash_Test(){
    int mul_hash_table[HASH_SIZE];
    for (int i=0; i < HASH_SIZE; i++)
        mul_hash_table[i] = 0;

    for(int i=0; i<10000;i ++)
        mul_hash_table[Multi_Hash(i, HASH_SIZE, 7)] += 1;

    for (int i=0; i < HASH_SIZE; i++)
        printf("key:%3d -> num_elems: %3d\n", i, mul_hash_table[i]);

    printf("------------------------------\n");

    for (int i=0; i < HASH_SIZE; i++)
        mul_hash_table[i] = 0;
    for(int i=0; i<10000;i +=2)
        mul_hash_table[Multi_Hash(i, HASH_SIZE, 7)] += 1;
    for (int i=0; i < HASH_SIZE; i++)
        printf("key:%3d -> num_elems: %3d\n", i, mul_hash_table[i]);
}







int main(int argc, char *argv[])
{
    Hash_Test();
    return 0;
}
