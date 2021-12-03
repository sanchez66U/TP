#ifndef _LST_ELM_
#define _LST_ELM_

#include <stdlib.h>	 // librairie standard
#include <stdio.h>	 // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>	 // librairie d'assertions

struct lst_elm_t
{
	void * datum;
	struct lst_elm_t *suc;
};

/** @brief create a new list element and store datum into it */
struct lst_elm_t * new_lst_elm_t(void * datum);
/** @brief destroy the list element pointed by E and set E to NULL */ 
void del_lst_elm_t(struct lst_elm_t ** ptrE);
/** @brief retreive the datum of the list element E */
void * getDatum(struct lst_elm_t * E);
/** @brief retreive the succesor of the list element E */
struct lst_elm_t * getSuc(struct lst_elm_t * E);
/** @brief modify the date of the list element */
void setDatum(struct lst_elm_t * E, void * datum);
/** @brief modify the succesor of the list element */
void setSuc(struct lst_elm_t * E, struct lst_elm_t * S);

#endif