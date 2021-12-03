#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

struct lst_elm_t *new_lst_elm(int value)
{
  struct lst_elm_t *E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
  assert(E != NULL);
  E->value = value;
  return E;
}

void del_lst_elm_t(struct lst_elm_t **ptrE)
{
  assert(E != NULL);
  free(*ptrE);
}

int getX(struct lst_elm_t *E)
{
  assert(E != NULL);
  return E->x;
}

struct lst_elm_t *getSuc(struct lst_elm_t *E)
{
  assert(E != NULL);
  return E->suc;
}

void setX(struct lst_elm_t *E, int v)
{
  assert(E != NULL);
  E->v = v;
}

void setSuc(struct lst_elm_t *E, struct lst_elm_t *S)
{
  assert(E != NULL);
  E->suc = S;
}