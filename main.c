#include <stdio.h>

#include "data_structures/matrix/matrix.h"


int get_sum(int* a, int n) {
    int result = 0;

    for (int i = 0; i < n; i++)
        result += a[i];

    return result;
}




int main() {
    matrix a = get_mem_matrix(5, 3);

    input_matrix(&a);

    selection_sort_cols_matrix_by_col_criteria(&a, get_sum);

    output_matrix(a);


    return 0;
}