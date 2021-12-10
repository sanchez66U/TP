#include <stdio.h>
#include <stdlib.h>
#include "pair.h"
#include "matrix.h"

int main()
{
    struct matrix *A;
    struct matrix *B;
    struct matrix *C;

    A = scanMatrix();
    B = scanMatrix();

    viewMatrix(A, "A =");
    viewMatrix(B, "B =");
    // Visualisation des deux matrices

    printf("Voulez additionner ces deux matrices ? (1 pour oui, 0 pour non)");
    scanf("%d", &rep);
    if (rep == 1)
    {
        printf("Addition des matrices : \n");
        C = addMatrix(A, B);
        viewMatrix(C, "A+B=");
    }
    else
    {
        printf("Voulez multiplier ces deux matrices ? (1 pour oui, 0 pour non)");
        scanf("%d", &rep2);
        if (rep2 == 1)
        {
            printf("Multiplication de matrice : \n");
            C = multMatrix(A, B);
            viewMatrix(C, "A*B=");
        }
        else
            printf("OK");
    }
    return 0;
}
