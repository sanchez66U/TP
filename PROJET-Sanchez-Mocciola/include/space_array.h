#ifndef _SPACE_ARRAY_
#define _SPACE_ARRAY_

#include <stdbool.h>
#include "global.h"
#include "objects.h"

typedef int state_t;

struct states_array_t {
  state_t * OPT;
  state_t * CHM;
  int num_obj;
  int Vmax;
};

void free_states_array(struct states_array_t * states);
struct states_array_t * new_states_array(const int num_objects, const int Vmax);
void push_object_in_array(struct states_array_t * states, const struct objects_t * objects, int i);
void view_path_array(const struct states_array_t * states, const struct objects_t * set);
void view_opt(const struct states_array_t * states);
void view_chm(const struct states_array_t * states);

#endif