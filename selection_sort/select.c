
#include<stdio.h>
#include<stdlib.h>

void print_arr(int** arr, int arr_length) {
    printf("[");
    for (int i = 0; i < arr_length; i++) {
        if (i != 0)
            printf(" ");

        printf("%d", i[(*arr)]);
    }
    printf("]\n");

    return;
}

void selectionSort (int **arr, int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        for (int j = i + 1; j < arr_length; j++) {
            if ((*arr)[j] < (*arr)[i]) {
                int temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
        
    return;
}

int main (void) {
    int num_inputs = 0;
    scanf("%d\n", &num_inputs);

    int *inputs = malloc(sizeof(int) * num_inputs);

    for (int i = 0; i < num_inputs; i++) {
        int input = 0;
        scanf("%d\n", &input);

        *(inputs + i) = input;
    }
    
    print_arr(&inputs, num_inputs);

    selectionSort(&inputs, num_inputs);

    print_arr(&inputs, num_inputs);

    return 0;
}
