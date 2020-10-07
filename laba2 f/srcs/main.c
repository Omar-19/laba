#include "../includes/header.h"


void generate_matrix(t_array *p)
{
    int i;
    for (i = 0; i < p->size; ++i)
    {
        p->A[i][i] = 4.0;
        if ((i + 1) < p->size)
            p->A[i][i + 1] = 1.0;
        if ((i - 1) >= 0)
            p->A[i][i - 1] = 1.0;
        p->B[i] = 10 - 2 * (i % 2);
    }
}


int main()
{
    t_array matrix;
    TYPE ESP = 0.0000001;

    matrix.size = 219;

    read_matrix(&matrix);

    generate_matrix(&matrix);

    // print_matrix_x_y(&matrix);

    seidel_method(&matrix, matrix.size, ESP);
    
    del_matrix(&matrix);
    return (0);
}
