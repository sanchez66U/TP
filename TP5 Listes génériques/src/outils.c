#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printInteger(int *i)
{
  assert(i);
  printf("La valeur est entière et vaut : %d\n", (*i));
}
void freeInteger(int *i)
{
  assert(i);
  free(i);
}

bool int_cmp(int *i, int *j)
{
  return (*i) < (*j);
}

void double_print(double *d)
{
  printf("La valeur est réelle et vaut : %lf\n", (*d));
}

void double_rm(double *d)
{
  free(d);
}

bool double_cmp(double *u, double *v)
{
  return (*u) < (*v);
}
