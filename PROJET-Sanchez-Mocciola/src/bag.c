#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "global.h"
#include "objects.h"
#include "prec.h"
#include "bag.h"
#include "lst.h"
#include "lst_elm_t.h"

struct retained_t *new_bag()
{
  struct retained_t *bagpack = (struct retained_t *)malloc(sizeof(struct retained_t));
  bagpack->objects_list = newLst();
  assert(bagpack->objects_list);
  bagpack->utilities_sum = 0;
  return bagpack;
}
void bagcpy(struct retained_t *duplicata, const struct retained_t *bagpack)
{
  duplicata->objects_list = listcpy(bagpack->objects_list);
  duplicata->utilities_sum = bagpack->utilities_sum;
}
void free_bag(struct retained_t **bagpack)
{
  assert(bagpack->objects_list != NULL);
  freeLst(bagpack->objects_list, void(*ptrf));
  bagpack->utilities_sum = NULL;
}
void clean_bag(struct retained_t *bagpack)
{
  assert(bagpack->objects_list != NULL);
  for (struct lst_elm_t *iterator = bagpack->objects_list->head; iterator;)
  {
    struct lst_elm_t *E = iterator;
    iterator = iterator->suc;
    del_elmlist(E, void(*ptrf));
  }
  bagpack->utilities_sum = 0;
}
void push_object_in_bag(struct retained_t *bagpack, struct object_t *ptr_object)
{
  assert(bagpack->objects_list != NULL);
  struct retained_t *E = new_bag();
  E->objects_list->suc = bagpack->objects_list->head;

  if (bagpack->objects_list->head)
    bagpack->objects_list->head->pred = E;
  else
    bagpack->objects_list->tail = E;

  bagpack->objects_list->head = E;
  bagpack->utilities_sum += 1;
}
void view_bagpack(struct retained_t *bagpack, const char *title)
{
  void (*ptr_view_fct)(const struct object_t *) = &view_object;
  printf("\n*****************\nVIEW BAGPACKAGING\t%s\n", title);
  view_list(bagpack->objects_list, ptr_view_fct);
  printf("\t\tWith utilities sum = %d\n\n", bagpack->utilities_sum);
}
