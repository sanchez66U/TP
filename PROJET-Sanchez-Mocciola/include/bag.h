#ifndef _DP_REC_
#define _DP_REC_

#include <assert.h>
#include <stdbool.h>
#include "lst.h"
#include "objects.h"

/**
 * TA to record objects retained as the one to put in the bag until now
 * booelan updated is set to false at the begining and to true as soon as
 * a list of objects fill up the bag as much as possible.
 **/
struct retained_t {
  struct lst_t * objects_list;
  int utilities_sum;
};

struct retained_t * new_bag();
void bagcpy(struct retained_t * newbagpack, const struct retained_t * bagpack);
void free_bag(struct retained_t * bagpack);
void clean_bag(struct retained_t * bagpack);
void push_object_in_bag(struct retained_t * bagpack, struct object_t * ptr_object);
void view_bagpack(struct retained_t * bagpack, const char * title);

#endif
