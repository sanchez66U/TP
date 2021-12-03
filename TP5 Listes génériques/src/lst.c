#include <stdlib.h>  // librairie standard
#include <stdio.h>   // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>  // librairie d'assertions

/*********************************
DÉCLARATIONS DES FONCTIONS PRIVÉES
*********************************/
void insert_after(struct lst_t *L, void *datum, struct lst_elm_t *place);

/**********************************
DÉFINITIONS DES FONCTIONS PUBLIQUES
**********************************/

bool empty_lst(const struct lst_t *L)
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

struct lst_elm_t *getHead(struct lst_t *L)
{
  assert(L != NULL);
  return L->head;
}

struct lst_elm_t *getTail(struct lst_t *L)
{
  assert(L != NULL);
  return L->tail;
}

int getNumelm(struct lst_t *L)
{
  assert(L != NULL);
  return L->numelm;
}

int setNumelm(struct lst_t *L, int numElm)
{
  assert(L != NULL);
  L->numelm = numElm;
}

void cons(struct lst_t *L, void *datum)
{
  struct lst_elm_t *E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
  E->datum = datum;
  E->suc = L->head;
  L->head = E;
  if (estVide(L))
  {
    L->tail = E;
  }
  L->numElm += 1;
}

void print_lst(struct lst_t *L, void (*ptrf)())
{
  printf("[ ");
  for (struct lst_elm_t *E = L->head; E; E = E->suc)
  {
    (*ptrf)(E->datum);
  }
  printf("]\n\n");
}

void del_lst(struct lst_t **ptrL, void (*prtFct)())
{
  struct lst_elm_t *E = (struct lst_elm_t *)calloc(l, sizeof(struct lst_elm_t));
  for (E = *ptrL->head; E != NULL; E = *ptrL->head)
  {
    *ptrL->head = E->suc;
    free(E);
  }
  free(ptrL);
}

void queue(struct lst_t *L, void *datum)
{
  struct lst_elm_t *E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
  setDatum(E, datum);
  if (empty_lst(L))
  {
    L->head = E;
  }
  else
  {
    setSuc(getTail(L), E);
  }
  L->tail = E;
  L->numElm += 1;
}

void view_lst(struct lst_t *L, void (*prtFct)())
{
  for (struct lst_elm_t *iter = L->head; iter; iter = iter->suc)
  {
    void *date = iter->datum;
    (*prtFct)(date);
  }
}

void insert_ordered(struct lst_t *L, void *datum, bool (*ptrFct)())
{
  if (empty_lst(L) || (*ptrFct)(datum, getDatum(getHead(L))))
  {
    cons(L, datum);
  }
  else if ((*ptrFct)(getDatum(getTail(L)), datum))
  {
    queue(L, datum);
  }
  else
  {
    struct lst_elm_t *pred = getHead(L);
    struct lst_elm_t *place = getSuc(pred);
    while (place && (*ptrFct)(getDatum(place), datum))
    {
      pred = place;
      place = getSuc(place);
    }
    insert_after(L, datum, pred);
  }
}

void insert_after(struct lst_t *L, void *datum, struct lst_elm_t *place)
{
  if (empty_lst(L) || !place)
  {
    cons(L, datum);
  }
  else if (place == getTail(L))
  {
    queue(L, datum);
  }
  else
  {
    struct lst_elm_t *E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
    setDatum(E, datum);
    setSuc(E, getSuc(place));
    setSuc(place, E);
    L->numElm += 1;
  }
}
