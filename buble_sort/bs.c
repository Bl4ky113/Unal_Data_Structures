
#include <stdio.h>
#include <stdlib.h>

void print_arr(int** arr, int arr_length) {
    printf("[");
    for (int i = 0; i < arr_length; i++) {
        if (i != 0)
            printf("\t");

        printf("%d", i[(*arr)]);
    }
    printf("]\n");

    return;
}

void bubble_sort (int **arr_p, int arr_length) {
    int sorted_index = arr_length;
    int *arr = *arr_p;

    while (sorted_index > 0) {
        int changed_index = 0;

        for (int i = 0; i < sorted_index - 1; i++) {
            if (arr[i] <= arr[i + 1]) {
                continue;
            }

            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;

            changed_index = i + 1;
        }

        sorted_index = changed_index;
    }

    return;
}


int main (void) {
    int *num_arr;
    int num_input = 0;

    scanf("%d\n", &num_input);

    num_arr = malloc(sizeof(int) * num_input);
    for (int i = 0; i < num_input; i++) {
        int usr_input; 
        scanf("%d\n", &usr_input);

        i[num_arr] = usr_input;
    }

    print_arr(&num_arr, num_input);

    bubble_sort(&num_arr, num_input);

    print_arr(&num_arr, num_input);
    return 0;
}
