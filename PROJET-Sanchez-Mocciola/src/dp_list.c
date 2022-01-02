#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "space_array.h"
#include "dp_array.h"
#include "dp_list.h"

void dp_list(const int Vmax, const struct objects_t *object_set)
{
    struct states_t *states = new_states_list();
    assert(states != NULL);
#ifdef _TRACE_
    view_states_list(states);
#endif

    for (int i = 1; i <= object_set->nb_objects; i += 1)
    {
#ifdef _TRACE_
        printf("#%d Object\n", i);
#endif
        push_object(object_set, states);
#ifdef _TRACE_
        view_states_list(states);
        view_state(states);
#endif
    }
    view_best_bagpack(states);
    free_states_list(states, &free_state);
}
