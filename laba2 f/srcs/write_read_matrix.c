#include "../includes/header.h"


void init_matrix_x_y_res(t_array *p)
{
    for(int i = 0; i < p->size; i++)
    {
        p->B[i] = 0.0;
        p->d[i] = 0.0;
        p->X[i] = 0.0;
        for(int j = 0; j < p->size; j++)
            p->A[i][j] = 0.0;
    }

    for(int i = 0; i < p->size; i++)
    {
        p->B[i] = 0.0;
        p->X[i] = 0.0;
    }
}


void read_matrix(t_array *p)
{
    int i,j, size;
    int num_y = 0;
    char *str;
    FILE *fp;

    // // try to open file with data
    // fp = fopen("dk.txt", "r");
    // if (fp==NULL){
    //     printf ("\nWhere is the file with my array, bro?\n\n");
    //     exit(0);
    // }

    // // read matrix size
    // fscanf(fp, "%d", &(p->size));
    p->A = (TYPE**)malloc(p->size * sizeof(TYPE*));

    // create memory
    for (i=0; i<p->size; i++)
        p->A[i] = (TYPE*)malloc(p->size * sizeof(TYPE));

    p->B = (TYPE*) malloc(p->size * sizeof(TYPE));

    p->d = (TYPE*) malloc(p->size * sizeof(TYPE));

    p->X = (TYPE*) malloc(p->size * sizeof(TYPE));

    init_matrix_x_y_res(p);

    // read X and Y matrixs
    // for (i = 0; i < p->size; i++)
    // {
    //     for (j = 0; j < (p->size + 1); j++)
    //     {
    //         // write in y matrix
    //         if (j == p->size){
    //             fscanf(fp, "%f", &p->B[num_y]);
    //             ++num_y;
    //             printf("%f\n", p->B[num_y]);
    //         }
    //         // write in x matrix
    //         else
    //             fscanf(fp, "%f ", &p->A[i][j]);
    //     }
    // }

    // fclose(fp);
}


// print matrix
void print_matrix_x_y(t_array *p)
{
    int i, j;

    // print matrix X
    printf("\n Matrix X \n\n");

    for (i = 0; i < p->size; i++)
    {
        for (j = 0; j < (p->size); j++)
            printf("%f\t", p->A[i][j]);

        printf("\n");
    }

    // print matrix y
    printf("\n Matrix Y \n\n");

    for(int i = 0; i < p->size; i++)
        printf("%f\n", p->B[i]);
    
    return;
}


void print_matrix(TYPE **arr, int size, char c)
{
    int i, j;

    // print matrix X
    printf("\n Matrix %c\n\n", c);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%f\t", arr[i][j]);

        printf("\n");
    }
}

// free memory
void del_matrix(t_array *p)
{
    int i;

    for (i=0; i<p->size; i++)
        free(p->A[i]);
    free(p->A);

    free(p->B);

    free(p->d);

    free(p->X);

    return;
}