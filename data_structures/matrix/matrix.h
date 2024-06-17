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


#endif //CODE_MATRIX_H