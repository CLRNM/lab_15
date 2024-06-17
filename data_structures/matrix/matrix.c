//
// Created by User.
//


#include <memory.h>
#include <malloc.h>
#include <stdio.h>

#include "matrix.h"


static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


static void copy_array(int a[], int b[], int n) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}



matrix get_mem_matrix(int n_rows, int n_cols) {
    int** values = (int**) malloc(sizeof(int*) * n_rows);

    for (size_t i = 0; i < n_rows; i++)
        values[i] = (int*) malloc(sizeof(int) * n_cols);

    return (matrix) {values, n_rows, n_cols};
}


matrix* get_mem_array_of_matrices(int n_matrices, int n_rows, int n_cols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * n_matrices);

    for (size_t i = 0; i < n_matrices; i++) {
        ms[i] = get_mem_matrix(n_rows, n_cols);
    }

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


void input_matrix(matrix  *m) {
    for (int i = 0; i < m->n_rows; i++) {
        printf("input %d row:", i + 1);
        for (int j = 0; j < m->n_cols; j++)
            scanf("%d", &m->values[i][j]); //
    }
}


void input_matrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++) {
        printf("input %lld matrix\n", i + 1);
        input_matrix(ms + i);
        printf("\n");
    }
}


void output_matrix(matrix  m) {
    for (size_t i = 0; i < m.n_rows; i++) {
        for (size_t j = 0; j < m.n_cols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}


void output_matrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++)
        output_matrix(ms[i]);
}


void swap_rows(matrix* m, int i1, int i2) {
    int* temp = m->values[i1];
    m->values[i1] = m->values[i2];
    m->values[i2] = temp;
}


void swap_columns(matrix* m, int j1, int j2) {
    for (int i = 0; i < m->n_rows; i++)
        swap(&m->values[i][j1], &m->values[i][j2]);
}


void insertion_sort_rows_matrix_by_row_criteria(matrix* m, int (*criteria) (int*, int)) {
    int res_criteria[m->n_rows];

    for (size_t i = 0; i < m->n_rows; i++)
        res_criteria[i] = criteria(m->values[i], m->n_cols);

    int i, j, key;
    int* address_key;
    for (i = 1; i < m->n_rows; i++) {
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;

        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swap_rows(m, j + 1, j);

            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}


void print(int a[], const size_t n) {
    printf("array: ");
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}



void selection_sort_cols_matrix_by_col_criteria(matrix* m, int (*criteria) (int*, int)) {
    int res_criteria[m->n_cols];

    for (size_t i = 0; i < m->n_cols; i++) {
        int temp[m->n_rows];
        for (size_t j = 0; j < m->n_rows; j++)
            temp[j] = m->values[j][i];

        res_criteria[i] = criteria(temp, m->n_rows);
    }

    int value_min_idx;
    for (int i = 0; i < m->n_cols; i++) {
        value_min_idx = i;

        for (int j = i + 1; j < m->n_cols; j++)
            if (res_criteria[j] < res_criteria[value_min_idx])
                value_min_idx = j;

        swap(&res_criteria[value_min_idx], &res_criteria[i]);
        swap_columns(m, value_min_idx, i);
    }
}