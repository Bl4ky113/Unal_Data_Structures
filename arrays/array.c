
#include <stdio.h>
#include <stdlib.h>

#define arr_size 10

int main (void) {
    int *arr = malloc(sizeof(int) * arr_size);

    for (int i = 0; i < arr_size; i++) {
        printf("%d\t", arr + i);
    }

    return 0;
}
