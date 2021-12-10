#include "pair.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

struct pair *consPair(int l, int c)
{
    struct pair *P = (struct pair *)malloc(sizeof(struct pair));
    P->l = l;
    P->c = c;
    return P;
}
struct pair *cpyPair(struct pair *P)
{
    struct pair *A = (struct pair *)malloc(sizeof(struct pair));
    A->l = P->l;
    A->c = P->c;
    return A;
}
void freePair(struct pair *P)
{
    free(P);
    P = NULL;
}
int pair2ind(struct pair *p, struct matrix *M)
{
    return (p->l) * (M->m) + (p->c);
}
struct pair *ind2pair(int k, struct matrix *M)
{
    struct pair *P = (struct pair *)malloc(sizeof(struct pair));
    P->l = k / M->n;
    P->c = k % M->n;
    return P;
}
