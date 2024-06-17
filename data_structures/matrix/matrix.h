//
// Created by User.
//


#ifndef CODE_MATRIX_H
#define CODE_MATRIX_H

#include <stdbool.h>


typedef struct matrix {
    int **values;
    int n_rows;
    int n_cols;
} matrix;


typedef struct position {
    int row_index;
    int col_index;
} position;


matrix get_mem_matrix(int n_rows, int n_cols);


matrix* get_mem_array_of_matrices(int n_matrices, int n_rows, int n_cols);


void free_mem_matrix(matrix *m);


void free_mem_matrices(matrix *ms, int n_matrices);


void input_matrix(matrix  *m);


void input_matrices(matrix *ms, int n_matrices);


void output_matrix(matrix* m);


void output_matrices(matrix *ms, int n_matrices);


void swap_rows(matrix* m, int i1, int i2);


void swap_columns(matrix* m, int j1, int j2);


void insertion_sort_rows_matrix_by_row_criteria(matrix* m, int (*criteria) (int*, int));


void selection_sort_cols_matrix_by_col_criteria(matrix* m, int (*criteria) (int*, int));


bool is_square_matrix(matrix* m);


bool are_two_matrices_equal(matrix* m1, matrix* m2);


bool is_E_matrix(matrix *m);


bool is_symmetric_matrix(matrix *m);


void transpose_square_matrix(matrix* m);


void transpose_matrix(matrix* m);


position get_min_value_pos(matrix m);


position get_max_value_pos(matrix m);


matrix create_matrix_from_array(const int a[], int n_rows, int n_cols);


matrix* create_array_of_matrix_from_array(const int values[], size_t n_matrices, size_t n_rows, size_t n_cols);

#endif //CODE_MATRIX_H