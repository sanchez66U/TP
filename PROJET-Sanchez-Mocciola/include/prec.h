#ifndef _PREC_
#define _PREC_

#include "objects.h"
#include <assert.h>
#include <stdbool.h>
#include "lst.h"
#include "bag.h"

struct retained_t
{
    struct lst_t * objects_list;
    int utilities_sum;
};

void prec(const int Vmax, struct objects_t * object_set, struct retained_t * bagpack);

#endif
