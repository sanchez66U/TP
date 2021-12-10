#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pair.h"
#include "matrix.h"

int main()
{
    struct matrix *A;
    struct matrix *B;
    struct matrix *C;

    A = matrixInput("data/A.txt");
    viewMatrix(A, "A :");

    B = matrixInput("data/B.txt");
    viewMatrix(B, "B :");
    // Visualisation des deux matrices

    printf("Voulez additionner ces deux matrices ? (1 pour oui, 0 pour non)");
    scanf("%d", &rep);
    if (rep == 1 && (A->n == B->n) && (A->m == B->m))
    {
        printf("Addition des matrices : \n");
        C = addMatrix(A, B);
        viewMatrix(C, "A+B=");
        saveMatrix(C, "data/MaDD.txt");
    }
    else
    {
        printf("Voulez multiplier ces deux matrices ? (1 pour oui, 0 pour non)");
        scanf("%d", &rep2);
        if (rep2 == 1 && (A->m == B->n))
        {
            printf("Multiplication de matrice : \n");
            C = multMatrix(A, B);
            viewMatrix(C, "A*B=");
            saveMatrix(C, "data/MMult.txt");
        }
        else
            printf("OK");
    }
    return 0;
}
