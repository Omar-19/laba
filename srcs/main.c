#include "../includes/header.h"


int main()
{
    t_array matrix;

    read_matrix(&matrix);
    // print_matrix_x_y(&matrix);

    TYPE det;

    if (Determinant(matrix.arr_x, matrix.size) == 0){
        printf("\nDET = 0, it's not ok. Try again with new input data :) \n\n");
        return (0);
    }
    create_LU_MATRIX(&matrix);
    solving_LU(&matrix);
    create_y_matrix(&matrix);
    print_matrix(matrix.arr_L, matrix.size, 'L');
    print_matrix(matrix.arr_U, matrix.size, 'U');
    solving_slough_with_LU(&matrix);

    // print_matrix_x_y(&matrix);

    printf("result\n");
    for (int i = 0; i < matrix.size; i++)
        printf("%f\n", matrix.result[i]);
    
    del_matrix(&matrix);
    exit(0);
    return (0);
}
