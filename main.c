#include <assert.h>

#include "data_structures/matrix/matrix.h"


void test_is_equal_matrix_1_is_equal() {
    matrix m1 = create_matrix_from_array((int[]){1, 2, 3, 4},2, 2);
    matrix m2 = get_mem_matrix(2, 2);
    m2.values[0][0] = 1;
    m2.values[0][1] = 2;
    m2.values[1][0] = 3;
    m2.values[1][1] = 4;


    bool res = are_two_matrices_equal(&m1, &m2);

    assert(res == 1);

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_is_equal_matrix_2_is_not_equal() {
    matrix m1 = create_matrix_from_array((int[]){7, 12, 3, 4},2, 2);
    matrix m2 = get_mem_matrix(2, 2);
    m2.values[0][0] = 1;
    m2.values[0][1] = 2;
    m2.values[1][0] = 3;
    m2.values[1][1] = 4;


    bool res = are_two_matrices_equal(&m1, &m2);

    assert(res == 0);

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_is_equal_matrix() {
    test_is_equal_matrix_1_is_equal();
    test_is_equal_matrix_2_is_not_equal();
}




void test_swap_rows_1_different_lines() {
    matrix m1 = create_matrix_from_array((int[]){1, 2, 3, 4}, 2, 2);
    matrix m2 = create_matrix_from_array((int[]){3, 4, 1, 2}, 2, 2);

    swap_rows(&m1, 0, 1);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_swap_rows_2_herself_to_herself() {
    matrix m1 = create_matrix_from_array((int[]){1, 2, 3, 4}, 2, 2);
    matrix m2 = create_matrix_from_array((int[]){1, 2, 3, 4}, 2, 2);

    swap_rows(&m1, 1, 1);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_swap_columns_1_different_columns() {
    matrix m1 = create_matrix_from_array((int[]){1, 2, 3,
                                                 4, 5, 6}, 2, 3);
    matrix m2 = create_matrix_from_array((int[]){1, 3, 2,
                                                 4, 6, 5}, 2, 3);

    swap_columns(&m1, 1, 2);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_swap_columns_2_herself_to_herself() {
    matrix m1 = create_matrix_from_array((int[]){1, 2, 3,
                                                 4, 5, 6}, 2, 3);
    matrix m2 = create_matrix_from_array((int[]){1, 2, 3,
                                                 4, 5, 6}, 2, 3);

    swap_columns(&m1, 1, 1);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_swap() {
    test_swap_rows_1_different_lines();
    test_swap_rows_2_herself_to_herself();
    test_swap_columns_1_different_columns();
    test_swap_columns_2_herself_to_herself();
}




// возвращает сумму элементов массива a размера n
int get_sum(int a[], int n) {
    int res = 0;
    for (size_t i = 0; i < n; i++)
        res += a[i];
    return res;
}


void test_sort_insertion_sort_rows_1_different_values() {
    matrix m1 = create_matrix_from_array((int[]){3, 12, 2,
                                                 4, 5, 6,
                                                 14, 8, 1}
            , 3, 3);

    matrix m2 = create_matrix_from_array((int[]) {4, 5, 6,
                                                  3, 12, 2,
                                                  14, 8, 1}
            , 3, 3);

    insertion_sort_rows_matrix_by_row_criteria(&m1, get_sum);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_sort_insertion_sort_rows_2_equal_values() {
    matrix m1 = create_matrix_from_array((int[]){1, 2, 3,
                                                 1, 5, 0,
                                                 1, 4, 1}
            , 3, 3);

    matrix m2 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  1, 5, 0,
                                                  1, 4, 1}
            , 3, 3);

    insertion_sort_rows_matrix_by_row_criteria(&m1, get_sum);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_sort_selection_sort_cols_1_different_values() {
    matrix m1 = create_matrix_from_array((int[]){3, 12, 2, // 21 25 9
                                                 4, 5, 6,
                                                 14, 8, 1}
            , 3, 3);

    matrix m2 = create_matrix_from_array((int[]) {2, 3, 12,
                                                  6, 4, 5,
                                                  1, 14, 8}
            , 3, 3);

    selection_sort_cols_matrix_by_col_criteria(&m1, get_sum);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_sort_selection_sort_cols_2_equal_values() {
    matrix m1 = create_matrix_from_array((int[]){3, 1, 9, // 21 25 9
                                                 4, 3, 0,
                                                 2, 5, 0}
            , 3, 3);

    matrix m2 = create_matrix_from_array((int[]) {3, 1, 9,
                                                  4, 3, 0,
                                                  2, 5, 0}
            , 3, 3);

    selection_sort_cols_matrix_by_col_criteria(&m1, get_sum);

    assert(are_two_matrices_equal(&m1, &m2));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}


void test_sort() {
    test_sort_insertion_sort_rows_1_different_values();
    test_sort_insertion_sort_rows_2_equal_values();
    test_sort_selection_sort_cols_1_different_values();
    test_sort_selection_sort_cols_2_equal_values();
}




void test_square_matrix_1_is_square() {
    matrix m = create_matrix_from_array((int[]) {1, 2,
                                                 3, 4}
            , 2, 2);

    assert(is_square_matrix(&m));

    free_mem_matrix(&m);
}


void test_square_matrix_2_is_not_square() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6}
            , 2, 3);

    assert(!is_square_matrix(&m));

    free_mem_matrix(&m);
}


void test_square_matrix() {
    test_square_matrix_1_is_square();
    test_square_matrix_2_is_not_square();
}




void test_e_matrix_1_is_e_matrix() {
    matrix e = create_matrix_from_array((int[]){1, 0, 0,
                                                0, 1, 0,
                                                0, 0, 1}
            , 3, 3);

    assert(is_E_matrix(&e));

    free_mem_matrix(&e);
}


void test_e_matrix_2_is_not_e_matrix() {
    matrix e = create_matrix_from_array((int[]){1, 2, 0,
                                                0, 1, 0,
                                                3, 0, 1}
            , 3, 3);

    assert(!is_E_matrix(&e));

    free_mem_matrix(&e);
}


void test_e_matrix() {
    test_e_matrix_1_is_e_matrix();
    test_e_matrix_2_is_not_e_matrix();
}




void test_symmetric_matrix_1_is_symmetric() {
    matrix s = create_matrix_from_array((int[]) {1, 2, 3,
                                                 2, 1, 5,
                                                 3, 5, 1}
            , 3, 3);
    assert(is_symmetric_matrix(&s));

    free_mem_matrix(&s);
}


void test_symmetric_matrix_2_is_not_symmetric() {
    matrix s = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}
            , 3, 3);
    assert(!is_symmetric_matrix(&s));

    free_mem_matrix(&s);
}


void test_symmetric_matrix() {
    test_symmetric_matrix_1_is_symmetric();
    test_symmetric_matrix_2_is_not_symmetric();
}




void test_transpose_matrix_1_transpose_square_matrix() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9},
                                        3, 3);

    matrix check = create_matrix_from_array((int[]) {1, 4, 7,
                                                     2, 5, 8,
                                                     3, 6, 9},
                                            3, 3);

    transpose_square_matrix(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_transpose_matrix_2_transpose_symmetric_matrix() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3,
                                                 2, 4, 5,
                                                 3, 5, 6},
                                        3, 3);

    matrix check = create_matrix_from_array((int[]) {1, 2, 3,
                                                     2, 4, 5,
                                                     3, 5, 6},
                                            3, 3);

    transpose_square_matrix(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_transpose_matrix_3_transpose_uni_matrix() {
    matrix m = create_matrix_from_array((int[]) {1},1, 1);
    matrix check = create_matrix_from_array((int[]) {1},1, 1);

    transpose_square_matrix(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_transpose_matrix_1_transpose_matrix() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3,
                                                 2, 4, 5},
                                        2, 3);

    matrix check = create_matrix_from_array((int[]) {1, 2,
                                                     2, 4,
                                                     3, 5},
                                            3, 2);

    transpose_matrix(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_transpose_matrix_2_transpose_uni_matrix() {
    matrix m = create_matrix_from_array((int[]) {7}, 1, 1);

    matrix check = create_matrix_from_array((int[]) {7}, 1, 1);

    transpose_matrix(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_transpose_matrix() {
    test_transpose_matrix_1_transpose_square_matrix();
    test_transpose_matrix_2_transpose_symmetric_matrix();
    test_transpose_matrix_3_transpose_uni_matrix();
    test_transpose_matrix_1_transpose_matrix();
    test_transpose_matrix_2_transpose_uni_matrix();
}




void test_get_value_1_get_min_value() {
    matrix m = create_matrix_from_array((int[]) {2, 1, 9, 0}, 2, 2);
    position res = get_min_value_pos(m);

    assert(res.row_index == 1 && res.col_index == 1);

    free_mem_matrix(&m);
}


void test_get_value_2_equal_value() {
    matrix m = create_matrix_from_array((int[]) {1, 1, 1, 1}, 2, 2);
    position res = get_min_value_pos(m);

    assert(res.row_index == 0 && res.col_index == 0);

    free_mem_matrix(&m);
}


void test_get_value_3_get_max_value() {
    matrix m = create_matrix_from_array((int[]) {2, 1, 9, 0}, 2, 2);
    position res = get_max_value_pos(m);

    assert(res.row_index == 1 && res.col_index == 0);

    free_mem_matrix(&m);
}


void test_get_value_4_equal_value() {
    matrix m = create_matrix_from_array((int[]) {7, 7, 7, 7}, 2, 2);
    position res = get_min_value_pos(m);

    assert(res.row_index == 0 && res.col_index == 0);

    free_mem_matrix(&m);
}


void test_get_value() {
    test_get_value_1_get_min_value();
    test_get_value_2_equal_value();
    test_get_value_3_get_max_value();
    test_get_value_4_equal_value();
}




void test() {
    test_is_equal_matrix();
    test_swap();
    test_sort();
    test_square_matrix();
    test_e_matrix();
    test_symmetric_matrix();
    test_transpose_matrix();
    test_get_value();
}


int main() {
    test();


    return 0;
}