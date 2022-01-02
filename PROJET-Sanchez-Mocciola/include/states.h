#ifndef _STATES_
#define _STATES_

#include <stdbool.h>
#include "global.h"

struct dyn_state_t
{
  struct lst_t *object_list;
  int volume;
  int utility;
};
typedef struct lst_t states_t;

struct dyn_state_t *null_state();
struct dyn_state_t *push_object(const struct object_t *O, struct dyn_state_t *S);
states_t *new_states_list();
void push_state(states_t *ptr_states, struct dyn_state_t *S);
void view_states_list(states_t *states);
void free_states_list(states_t *states, void (*ptr_fct)());
void free_state(struct dyn_state_t *S);
void view_state(const struct dyn_state_t *S);
struct dyn_state_t *best_bagpack(const states_t *states);
void view_best_bagpack(struct dyn_state_t *S);
states_t *cpy_states_list(states_t *ptr_states);
#endif
