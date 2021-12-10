#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "pair.h"

struct matrix *consMatrix(int n, int m)
{
    struct matrix *P = (struct matrix *)malloc(sizeof(struct matrix));
    P->values = (double *)calloc(n * m, sizeof(double));
    P->n = n;
    P->m = m;
    return P;
}
// Alloue la m ́emoire et initialise les champs m et n.

struct matrix *cpyMatrix(struct matrix *M)
{
    struct matrix *copy = consMatrix(M->n, M->m);
    copy->n = M->n;
    copy->m = M->m;

    for (int i = 0; i < (M->n) * (M->m); i++)
    {
        copy->values[i] = M->values[i];
    }
    return copy;
}
// Creer une copie exacte de la matrice M.

void freeMatrix(struct matrix **M)
{
    for (int i = 0; i < ((*M)->n) * ((*M)->m); i++)
    {
        free(*M);
    }
    *M = NULL;
}
// Libere toute la m ́emoire occup ́ee par *M et met celle-ci `a NULL.

void viewMatrix(struct matrix *M, char *entete)
{
    printf("Matrice : %s\n", entete);
    for (int i = 0; i < (M->n) * (M->m); i++)
    {
        printf("|%f|", M->values[i]);
        if ((i + 1) % M->m == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
// Visualise la matrice M apres avoir affiche son entete.

struct matrix *scanMatrix()
{
    int n, m;

    printf("Donnez le nombre de lignes : ");
    scanf("%d", &n);

    printf("Donnez le nombre de colonnes : ");
    scanf("%d", &m);

    struct matrix *M = consMatrix(n, m);

    for (int i = 0; i < (M->n) * (M->m); i++)
    {
        printf("M: ");
        scanf("%lf", &(M->values[i]));
    }

    return M;
}

struct matrix *addMatrix(struct matrix *A, struct matrix *B)
{
    struct matrix *M = consMatrix(A->n, A->m);

    for (int i = 0; i < (A->n) * (A->m); i++)
    {
        M->values[i] = A->values[i] + B->values[i];
    }
    return M;
}
struct matrix *multMatrix(struct matrix *A, struct matrix *B)
{
    struct matrix *M = consMatrix(A->n, B->m);

    for (int i = 0; i < M->n; i++)
    {

        for (int j = 0; j < M->m; j++)
        {
            struct pair *PIJ = consPair(i, j);
            int IIJ = pair2ind(PIJ, C);

            for (int k = 0; k < A->m; k++)
            {

                struct pair *PIK = consPair(i, k);
                int IIK = pair2ind(PIK, A);

                struct pair *PKJ = consPair(k, j);
                int IKJ = pair2ind(PKJ, B);

                M->values[IIJ] += (A->values[IIK]) * (B->values[IKJ]);
            }
        }
    }
    return M;
}
