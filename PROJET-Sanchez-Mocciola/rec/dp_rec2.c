#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "global.h"
#include "objects.h"
#include "prec.h"

void prec(const int Vmax, struct objects_t *obj_set, struct retained_t *bag)
{
  const int nbobjects = obj_set->nb_objects;
  struct retained_t *duplicata = (struct retained_t$)malloc(sizeof(struct retained_t));
  bagcpy(duplicata, bag);
  struct retained_t *best_bagpack = (struct retained_t$)malloc(sizeof(struct retained_t));
  bagcpy(duplicata, best_bagpack);
  for (int obj = object_set->first_idx; obj < nbobjects; obj++)
  {
    struct object_t *ptrobject = *obj_set;
    int volume = bag->utilities_sum;
    if (volume != NULL)
    {
      bagcpy(duplicata, bag);
      push_object_in_bag(bag, obj_set);
      obj_set->first_idx = bag->utilities_sum;
      prec(Vmax, ptrobject, best_bagpack);
      if (best_backpack->utilities_sum <= duplicata->utilities_sum)
      {
        clean_bag(duplicata);
        bagcpy(best_bagpack, duplicata);
      }
    }
  }
  clean_bag(bag);
  bagcpy(bag, best_bagpack);
  free_bag(best_bagpack);
}
