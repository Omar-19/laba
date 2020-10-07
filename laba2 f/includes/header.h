#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

// #define TYPE double
#define TYPE float

typedef struct	s_array
{
	int     size;
	TYPE**    A;
	TYPE*     d;
    TYPE*     B;
	TYPE*     X;
}				t_array;


void	read_matrix(t_array *p);
void	print_matrix_x_y(t_array *p);
void	del_matrix(t_array *p);
void	init_matrix_x_y_res(t_array *p);
// bool	converge(double xk[10], double xkp[10], int n, double eps);
// TYPE	okr(double x, double eps);
// bool	diagonal(double a[10][10], int n);
void	seidel_method(t_array *p, int n, TYPE ESP);
void 	generate_matrix(t_array *p);

#endif