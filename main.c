#include <stdio.h>

#include "data_structures/matrix/matrix.h"


int get_sum(int* a, int n) {
    int result = 0;

    for (int i = 0; i < n; i++)
        result += a[i];

    return result;
}




int main() {
    matrix a = get_mem_matrix(3, 3);

    input_matrix(&a);

    printf("yes");


    return 0;
}