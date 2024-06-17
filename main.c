#include <stdio.h>

#include "data_structures/matrix/matrix.h"


int get_sum(int* a, int n) {
    int result = 0;

    for (int i = 0; i < n; i++)
        result += a[i];

    return result;
}




int main() {
    matrix a = get_mem_matrix(4, 3);

    input_matrix(&a);

    transpose_square_matrix(&a);

    output_matrix(&a);

    return 0;
}