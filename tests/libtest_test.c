
#include <stdio.h>
#include "test.h"

int main (void) {
    int foo = sum(10, 5);
    int bar = sub(10, 5);

    printf("%d\t%d\n", foo, bar);
    return 0;
}
