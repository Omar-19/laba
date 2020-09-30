#include "../includes/header.h"

void create_LU_MATRIX(t_array *p)
{
    int i;

    p->arr_L = (TYPE**)malloc(p->size * sizeof(TYPE*));
    for (i=0; i<p->size; i++)
        p->arr_L[i] = (TYPE*)malloc(p->size * sizeof(TYPE));

    p->arr_U = (TYPE**)malloc(p->size * sizeof(TYPE*));
    for (i=0; i<p->size; i++)
        p->arr_U[i] = (TYPE*)malloc(p->size * sizeof(TYPE));
    
    init_U_by_x_L_by_zero(p);
}


void init_U_by_x_L_by_zero(t_array *p)
{
    for(int i = 0; i < p->size; i++)
        for(int j = 0; j < p->size; j++)
        {
            p->arr_U[i][j] = p->arr_x[i][j];
            p->arr_L[i][j] = 0.0;
        }
}


void func_error(char c)
{
    printf("You have problem with matrix U %c\n", c);
    exit(0);
}


void create_y_matrix(t_array *p)
{
    TYPE sum;

    for (int i = 1; i < p->size; i++)
    {
        sum = 0.0;
        for (int j = 0; j < i; j++)
            sum += p->arr_y[j] * p->arr_L[i][j];
        p->arr_y[i] = p->arr_y[i] - sum;
    }
}


void solving_LU(t_array *p)
{
	for(int i = 0; i < p->size; i++)
		for(int j = i; j < p->size; j++)
        {
            if (p->arr_U[i][i] == 0)
                func_error('a');
			p->arr_L[j][i] = p->arr_U[j][i] / p->arr_U[i][i];
        }
	
	for(int k = 1; k < p->size; k++)
	{
		for(int i = k-1; i < p->size; i++)
			for(int j = i; j < p->size; j++)
            {
                if (p->arr_U[i][i] == 0)
                    func_error('b');
				p->arr_L[j][i] = p->arr_U[j][i] / p->arr_U[i][i];
            }

		for(int i = k; i < p->size; i++)
			for(int j = k-1; j < p->size; j++)
				p->arr_U[i][j] = p->arr_U[i][j] - p->arr_L[i][k-1] * p->arr_U[k-1][j];
	}

}


void solving_slough_with_LU(t_array *p)
{
    TYPE sum;

    for (int i = (p->size - 1); i >= 0; i--)
    {
        sum = 0.0;
        for (int j = i + 1; j < p->size; j++)
        {   
            sum += (p->arr_U[i][j] * p->result[j]);
        }

        if (p->arr_U[i][i] == 0)
            func_error('c');
        p->result[i] = (p->arr_y[i] - sum) / p->arr_U[i][i];
    }
}
