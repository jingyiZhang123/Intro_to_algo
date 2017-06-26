#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH_1 10
#define ARRAY_LENGTH_2 20

int main(int argc, char **argv) {
    int* arr = malloc(sizeof(int) * 10);

    for (int i=0; i<10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (int i=0; i<10; i++)
        arr[i] = i;
    for (int i=0; i<10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    arr = (int*)realloc(arr, 20*sizeof(int));
    for (int i=0; i<20; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);

    arr = calloc(20, sizeof(int));
    for (int i=0; i<20; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
