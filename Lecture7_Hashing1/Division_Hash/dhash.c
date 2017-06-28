#include "dhash.h"

#include <stdio.h>
#include <stdlib.h>

extern int Division_Hash(int key, int num_slots);


int Division_Hash(int key, int num_slots){
    return key % num_slots;
}
