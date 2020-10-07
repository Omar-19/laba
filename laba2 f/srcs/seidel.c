#include "../includes/header.h"

// Условие окончания
bool converge(double xk[10], double xkp[10], int n, double eps)
{
	double norm = 0;
	for (int i = 0; i < n; i++)
		norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
	return (sqrt(norm) < eps);
}

TYPE okr(TYPE x, double eps)
{
	int i = 0;
	while (eps != 1)
	{
		i++;
		eps *= 10;
	}
	int okr = pow((double)(10), i);
	x = (int)(x * okr + 0.5) / (double)(okr);

	return x;
}

bool diagonal(TYPE **a, int n)
{
	int i, j, k = 1;
	TYPE sum;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < n; j++) sum += a[i][j];
		sum -= a[i][i];
		if (sum > a[i][i]) 
		{
			k = 0; 
            printf("%f < %f", a[i][i], sum);
		}
		else
			printf("%f > %f", a[i][i], sum);
		

	}

	return (k == 1);

}


void seidel_method(t_array *p, int n, TYPE epp)
{
    TYPE sum, maxdp=0, a, temp, error;
    int flag;
    int i, j, count, t;
    int m = 40;
    
    //Производится решение методом Зейделя
    while (m > 0) {
        for (i = 0; i < n; i++) {
            p->d[i] = (p->B[i] / p->A[i][i]);
            for (j = 0; j < n; j++) {
                if (j == i)
                    continue;
                p->d[i] = p->d[i] - ((p->A[i][j] / p->A[i][i]) * p->X[j]);
                p->X[i] = p->d[i];
            }
        }
        --m;
    }

    printf("\n%s\n", "X result");
    for (i = 0; i < n; ++i)
    {
        printf("X[%d]=%lf  %d\n", i, p->d[i], (2 - (i % 2)));
    }

    return;
}
