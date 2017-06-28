#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dhash.h"

// do NOT pick the hash size with a small divisor. prime number is preferred
// and not too close to the power of 2 or 10
#define HASH_SIZE 151

void Hash_Test(){
    int div_hash_table[HASH_SIZE];
    for (int i=0; i < HASH_SIZE; i++)
        div_hash_table[i] = 0;

    for(int i=0; i<10000;i ++)
        div_hash_table[Division_Hash(rand(), HASH_SIZE)] += 1;

    for (int i=0; i < HASH_SIZE; i++)
        printf("key:%3d -> num_elems: %3d\n", i, div_hash_table[i]);

    printf("------------------------------\n");
    // bad case1 test
    // size of hash table is 100 (100 has a divisor 2)
    for (int i=0; i < 100; i++)
        div_hash_table[i] = 0;

    // all the keys are even as well
    for(int i=0; i<10000;i +=2)
        div_hash_table[Division_Hash(i, 100)] += 1;
    // all odd slots are empty, because the result of even number mod even number must an even number.
    for (int i=0; i < 100; i++)
        printf("key:%3d -> num_elems: %3d\n", i, div_hash_table[i]);





}

int main(int argc, char *argv[])
{
    Hash_Test();
    return 0;
}
