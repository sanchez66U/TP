#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "global.h"
#include "objects.h"
#include "prec.h"

struct objects_t *new_objects(int argc, char **argv, bool utility)
{
    struct objects_t *set = malloc(sizeof(struct objects_t));
    int i, offset = 4;
    set->nb_objects = (utility) ? (argc - offset) / 2 : (argc - offset);
    set->objects = malloc(sizeof(struct Object) * set->nb_objects);
    if (utility)
    {
        int j;
        for (i = offset, j = 0; i < argc; i += 2, j += 1)
        {
            set->objects[j].volume = argv[i];
            set->objects[j].utility = argv[i + 1];
        }
    }
    else
        for (i = offset; i < argc; i += 1)
        {
            set->objects[i - offset].volume = argv[i];
            set->objects[i - offset].utility = argv[i];
        }
    return set;
}
