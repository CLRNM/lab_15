//
// Created by User.
//


#include <memory.h>
#include <malloc.h>

#include "matrix.h"

matrix get_mem_matrix(int n_rows, int n_cols) {
    int** values = (int**) malloc(sizeof(int) * n_rows);

    for (size_t i = 0; i < n_rows; i++)
        values[i] = (int*) malloc(sizeof(int) * n_cols);

    return (matrix) {values, n_rows, n_cols};
}


matrix* get_mem_array_of_matrices(int n_matrices, int n_rows, int n_cols) {
    matrix* ms = (matrix*) malloc(sizeof(matrix) * n_matrices);

    for (size_t i = 0; i < n_matrices; i++)
        ms[i] = get_mem_matrix(n_rows, n_cols);

    return ms;
}


void free_mem_matrix(matrix *m) {
    for (size_t i = 0; i < m->n_rows; i++)
        free(m + i);

    free(m->values);
    m->values = NULL;
    m->n_rows = 0;
    m->n_cols = 0;
}


void free_mem_matrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++)
        free_mem_matrix(ms + i);

    free(ms->values);
    ms->values = NULL;
    ms->n_rows = 0;
    ms->n_cols = 0;
}