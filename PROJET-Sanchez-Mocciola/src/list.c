#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "form.h"
#include "lst_elm_t.h"
#include "lst.h"

/*********************************
DÉCLARATIONS DES FONCTIONS PRIVÉES
*********************************/
void insert_after(struct lst_t *L, void *data, struct lst_elm_t *ptrelm);

/**********************************
DÉFINITIONS DES FONCTIONS PUBLIQUES
**********************************/

struct lst_t *newLst()
{
  struct lst_t *L = (struct lst_t *)calloc(1, sizeof(struct lst_t));
  assert(L != NULL);
  return L;
}

void freeLst(struct lst_t **L, void (*ptrf)())
{
  assert(L != NULL);
  for (struct lst_elm_t *iterator = L->head; iterator;)
  {
    struct lst_elm_t *E = iterator;
    iterator = iterator->suc;
    del_elmlist(E, ptrf);
  }
  free(L);
}

bool emptyLst(struct lst_t *L)
{
  assert(L != NULL);
  return L->numelm == 0;
}

/*
    Accessors & Modifiers
*/
struct lst_elm_t *get_head(struct lst_t *L)
{
  assert(L != NULL);
  return L->head;
}

struct lst_elm_t *get_tail(struct lst_t *L)
{
  assert(L != NULL);
  return L->tail;
}

// Add on head
void cons(struct lst_t *L, void *data)
{
  assert(L != NULL);
  struct lst_elm_t *E = new_elmlist(data);
  E->suc = L->head;
  if (L->head)
  {
    L->head->pred = E;
  }
  else
  {
    L->tail = E;
  }
  L->head = E;
  L->numelm += 1;
}

// Add on tail
void queue(struct lst_t *L, void *data)
{
  assert(L != NULL);
  struct lst_elm_t *E = new_elmlist(data);
  E->pred = L->tail;
  if (L->tail)
  {
    L->tail->suc = E;
  }
  else
  {
    L->head = E;
  }
  L->tail = E;
  L->numelm += 1;
}

void ordered_insert(struct lst_t *L, void *data, bool (*ptrf)())
{
  if (freeLst(L) || (*ptrf)(data, get_data(cons(L))))
  {
    cons(L, data);
  }
  else if ((*ptrf)(get_data(queue(L)), data))
  {
    queue(L, data);
  }
  else
  {
    struct lst_elm_t *iterator = L->head;
    bool found = false;
    while (iterator && !found)
    {
      found = (*ptrf)(data, get_data(iterator));
      if (!found)
      {
        iterator = iterator->suc;
      }
    }
    insert_after(L, data, iterator->pred);
  }
}

void printLst(struct lst_t *L, void (*ptrf)())
{
  printf("\t\t====================\n");
  printf("\t\t|| View data list ||\n");
  printf("\t\t====================\n");
  if (is_empty(L))
  {
    printf("[ ] //empty list\n");
  }
  else
  {
    struct lst_elm_t *iterator = L->head;
    while (iterator)
    {
      view_elmlist(iterator, ptrf);
      iterator = iterator->suc;
    }
  }
}

void insert_after(struct lst_t *L, void *data, struct lst_elm_t *place)
{
  assert(L != NULL);
  if (is_empty(L) || !place)
  {
    cons(L, data);
  }
  else if (place == queue(L))
  {
    queue(L, data);
  }
  else
  {
    struct lst_elm_t *E = new_elmlist(data);
    E->pred = place;
    if (place == L->tail)
    {
      L->tail = E;
    }
    else
    {
      place->suc->pred = E;
    }
    E->suc = place->suc;
    place->suc = E;
    L->numelm += 1;
  }
}
