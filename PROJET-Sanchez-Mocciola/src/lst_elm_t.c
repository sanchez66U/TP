#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "form.h"
#include "lst_elm_t.h"

struct lst_elm_t *new_elmlist(void *data)
{
  struct lst_elm_t *E = (struct lst_elm_t *)calloc(1, sizeof(struct lst_elm_t));
  assert(E != NULL);
  E->data = data;
  return E;
}

void del_elmlist(struct lst_elm_t **E, void (*ptrf)())
{
  assert(E != NULL);
  (*ptrf)(E->data);
  free(E);
}

struct lst_elm_t *get_suc(struct lst_elm_t *E)
{
  assert(E != NULL);
  return E->suc;
}

struct lst_elm_t *get_pred(struct lst_elm_t *E)
{
  assert(E != NULL);
  return E->pred;
}

void *get_data(struct lst_elm_t *E)
{
  assert(E != NULL);
  return E->data;
}

void set_suc(struct lst_elm_t *E, struct lst_elm_t *S)
{
  assert(E != NULL);
  E->suc = S;
}

void set_pred(struct lst_elm_t *E, struct lst_elm_t *P)
{
  assert(E != NULL);
  E->pred = P;
}

void set_data(struct lst_elm_t *E, void *data)
{
  assert(E != NULL);
  E->data = data;
}

void view_elmlist(struct lst_elm_t *E, void (*ptrf)())
{
  (*ptrf)(E->data);
}
