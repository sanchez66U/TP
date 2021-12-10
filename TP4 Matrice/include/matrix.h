#ifndef matrix_h
#define matrix_h

struct matrix
{
    double *values;
    int n, m;
};

struct matrix *consMatrix(int n, int m);
struct matrix *cpyMatrix(struct matrix *M);
void freeMatrix(struct matrix **M);
void viewMatrix(struct matrix *M, char *entete);
struct matrix *scanMatrix();
struct matrix *addMatrix(struct matrix *A, struct matrix *B);
struct matrix *multMatrix(struct matrix *A, struct matrix *B);

#endif /* matrix_h */
