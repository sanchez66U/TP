#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "space_array.h"

void free_states_array(struct states_array_t *states)
{
  assert(states);
  for (struct states_array_t *iterator = L->head; iterator;)
    free(*states);
  states->num_obj = NULL;
  states->Vmax = NULL;
}

struct states_array_t *new_states_array(const int num_objects, const int Vmax)
{
  struct states_array_t *NS = (struct states_array_t *)malloc(sizeof(struct states_array_t));
  assert(NS != NULL);
  NS->CHM = (struct states_array_t *)malloc(sizeof(struct states_array_t));
  NS->num_obj = num_objects;
  NS->Vmax = Vmax;

  init_opt_chm(NS);
  return NS;
}
