#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

struct lst_elm_t *new_lst_elm(void *datum)
{
  struct lst_elm_t *E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
  assert(E != NULL);
  E->datum = datum;
  return E;
}

void del_lst_elm(struct lst_elm_t **ptrE)
{
  assert(E != NULL);
  free(*ptrE);
}

int getDatum(struct lst_elm_t *E)
{
  assert(E != NULL);
  return E->x;
}

struct lst_elm_t *getSuc(struct lst_elm_t *E)
{
  assert(E != NULL);
  return E->suc;
}

void setDatum(struct lst_elm_t *E, void *datum)
{
  assert(E != NULL);
  E->v = v;
}

void setSuc(struct lst_elm_t *E, struct lst_elm_t *S)
{
  assert(E != NULL);
  E->suc = S;
}