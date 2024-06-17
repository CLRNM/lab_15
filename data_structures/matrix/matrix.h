//
// Created by User.
//


#ifndef CODE_MATRIX_H
#define CODE_MATRIX_H


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


void output_matrix(matrix  m);


void output_matrices(matrix *ms, int n_matrices);


void swap_rows(matrix* m, int i1, int i2);


void swap_columns(matrix* m, int j1, int j2);


void insertion_sort_rows_matrix_by_row_criteria(matrix* m, int (*criteria) (int*, int));


void selection_sort_cols_matrix_by_col_criteria(matrix* m, int (*criteria) (int*, int));


#endif //CODE_MATRIX_H