#ifndef _LST_ELM_
#define _LST_ELM_

#include <stdlib.h>	 // librairie standard
#include <stdio.h>	 // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>	 // librairie d'assertions

struct lst_elm_t
{
	void *datum;
	struct lst_elm_t *suc;
};

/** @brief create a new list element and store datum into it */
struct lst_elm_t *new_lst_elm(void *datum);

void del_lst_elm(struct lst_elm_t **ptrE);

int getDatum(struct lst_elm_t *E);
struct lst_elm_t *getSuc(struct lst_elm_t *E);
void setDatum(struct lst_elm_t *E, void *datum);
void setSuc(struct lst_elm_t *E, struct lst_elm_t *S);

#endif