#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

// #define TYPE double
#define TYPE float

typedef struct	s_array
{
	int     size;
	TYPE**    arr_x;
	TYPE**    arr_L;
	TYPE**    arr_U;
    TYPE*    arr_y;
	TYPE*    result;
}				t_array;


void 			Transpose(TYPE **a,int n);
TYPE			Determinant(TYPE **a, int n);
void 			CoFactor(TYPE **a, int n, TYPE **b);
void            read_matrix(t_array *p);
void            print_matrix_x_y(t_array *p);
void 			print_matrix(TYPE **arr, int size, char c);
void            del_matrix(t_array *p);
TYPE			Determinant(TYPE **a,int n);
void 			CoFactor(TYPE **a, int n, TYPE **b);
void			Transpose(TYPE **a,int n);
void			create_LU_MATRIX(t_array *p);
void			solving_slough_with_LU(t_array *p);
void			solving_LU(t_array *p);
void			func_error(char c);
void 			init_U_by_x_L_by_zero(t_array *p);
void			init_matrix_x_y_res(t_array *p);
void 			create_y_matrix(t_array *p);

#endif