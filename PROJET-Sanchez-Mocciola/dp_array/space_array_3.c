#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "space_array.h"
#include "global.h"

void view_path_array(struct states_array_t *states, struct objects_t *set)
{
  int obj = states->num_obj;
  int vol = states->Vmax;
  int idx = obj * (states->Vmax + 1) + vol;
  bool stop = (obj == 0);
  printf("******\nTotal packaging utility : %d\n******\n", states->OPT[idx]);
  while (!stop)
  {
    if (states->CHM[idx] != INFTY)
    { // object actually put in bag
      printf("\tobjet #%d(%d, %d)\n", obj, set->objects[obj - 1].volume, set->objects[obj - 1].utility);
      stop = (states->CHM[idx] == 0);
      vol = states->CHM[idx];
    }
    obj -= 1;
    stop = stop || (obj == 0);
    idx = obj * (states->Vmax + 1) + vol;
  }
  printf("\n");
}