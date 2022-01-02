#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "space_array.h"
#include "global.h"

/**
 * Private Function
 **/
void init_opt_chm(struct states_array_t *states)
{
    int idx;
    states->OPT = (struct states_array_t *)malloc(sizeof(struct states_array_t));
    states->CHM = (struct states_array_t *)malloc(sizeof(struct states_array_t));
    for (int obj = 1; obj <= states->num_obj; obj += 1)
    {
        for (int bag = 0; bag <= states->Vmax; bag += 1)
        {
            idx = bag;
            states->OPT[idx] = UNDTR;
            states->CHM[idx] = UNDTR;
        }
    }
    for (int bag2 = 0; bag2 <= states->Vmax; bag2 += 1)
        states->CHM[bag2] = UNDTR;
}