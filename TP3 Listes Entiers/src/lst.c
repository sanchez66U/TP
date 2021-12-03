#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

/*********************************
DÉCLARATIONS DES FONCTIONS PRIVÉES
*********************************/
void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place);

/**********************************
DÉFINITIONS DES FONCTIONS PUBLIQUES
**********************************/

bool emptyLst(const struct lst_t *L)
{
  assert(L);
  return L->numelm == 0;
}

struct lst_t *newLst()
{
  struct lst_t *L = (struct lst_t *)calloc(1, sizeof(struct lst_t));
  assert(L);
  return L;
}

void cons(struct lst_t *L, int v)
{
  assert(L != NULL);
  struct lst_elm_t *E = new_lst_elm(value);
  E->suc = L->head;
  if (emptyLst(L))
  {
    L->tail = E;
  }
  L->head = E;
  L->numelm += 1;
}

void printLst(struct lst_t *L)
{
  printf("[ ");
  for (struct lst_elm_t *E = L->head; E; E = E->suc)
  {
    printf("%d ", E->x);
  }
  printf("]\n\n");
}

void del_lst(struct lst_t **ptrL)
{
  struct lst_elm_t *L = *ptrL;
  while (!emptyLst(L))
  {
    struct lst_elm_t *E = L;
    L = L->suc;

    free(E);
  }
  L = consVide();
}

void queue(struct lst_t *L, void *data)
{
  assert(L != NULL);
  struct lst_elm_t *E = new_lst_elm(value);
  E->x = data;
  E->suc = NULL;
  L->numelm++;

  if (L->numelm == 1)
  {
    L->tail = E;
    L->head = E;
  }
  else
    L->tail->suc = E;
}

void insert_ordered(struct lst_t *L, const int value)
{
  assert(L != NULL);
  if (emptyLst(L))
  {
    cons(L, value);
  }
  else if (value < L->head)
  {
    cons(L, value);
  }
  else if (value > L->tail)
  {
    queue(L, value);
  }
  else
  {
    struct lst_elm_t *E = new_lst_elm(value);
    for (struct lst_elm_t *i = L->head; i->suc->X; i = i->suc)
    {
      E = i;
    }
    insert_after(L, value, E);
  }
}

void insert_after(struct lst_t *L, const int value, struct lst_elm_t *place);
{
  assert(L != NULL);
  if (emptyLst(L) || !place)
  {
    cons(L, value)
  }
  else
  {
    struct lst_elm_t *E = new_lst_elm(value);
    E->x = value;
    E->suc = place;
    if (place == L->tail)
    {
      L->tail = E;
    }
    else
    {
      place->suc = E;
    }
    E->suc = place->suc;
    place->suc = E;
    L->numelm += 1;
  }
}