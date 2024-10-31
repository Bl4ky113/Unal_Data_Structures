
#include <iostream>

#define arr_size 10

int main (void) {
    int *arr = new int[arr_size];

    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << "\t";
    }

    std::cout << std::endl;

    for (int i = 0; i < arr_size; i++) {
        std::cout << arr + i << "\t";
    }

    return 0;
}
