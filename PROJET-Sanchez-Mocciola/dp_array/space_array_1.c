#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "space_array.h"
#include "global.h"

void push_object_in_array(struct states_array_t *S, struct objects_t *LO, int i)
{
  for (int bag = 0; bag < (S->Vmax + 1); bag += 1)
  {

    int y = (i - 1) * (S->Vmax + 1) + bag;
    int x = i * (S->Vmax + 1) + bag;
    int OPT2 = S->OPT[y];
    S->CHM[x] = INFTY;
    if (LO->LO[index].volume <= bag)
    {
      int ysansI = (i - 1) * ((S->Vmax + 1 - LO->LO[x].volume) + LO->objects[x].utility) + bag;
      int OPT3 = S->OPT[ysansI];
      if (S->OPT[x] > S->OPT[y])
      {
        S->OPT[x] = OPT2;
        S->CHM[x] = S->OPT[ysansI];
      }
      else
        S->OPT[x] = OPT3;
    }
    else
      S->OPT[x] = UNDTR;
  }
}
