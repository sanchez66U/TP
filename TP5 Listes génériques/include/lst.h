#ifndef _LST_
#define _LST_

#include <stdlib.h>	 // librairie standard
#include <stdio.h>	 // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>	 // librairie d'assertions

/** @brief Le type d'une liste :
	* + head - le premier élément de la liste
	* + tail - le dernier élément de la liste
	* + numelm - le nombre d'élément dans la liste
*/
struct lst_t
{
	struct lst_elm_t *head;
	struct lst_elm_t *tail;
	int numelm;
};
/** @brief Vérifier si la liste L est vide ou pas */
bool empty_lst(const struct lst_t *L);

/** @brief Construire une liste vide */
struct lst_t *newLst();

/** @brief Ajouter en tête de la liste L la valeur v */
void cons(struct lst_t *L, void *datum);

void queue(struct lst_t *L, void *datum);

/** @brief Visualiser les éléments de la liste L */
void print_lst(struct lst_t *L, void (*ptrf)());

/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t **ptrL, void (*ptrFct)());

void insert_ordered(struct lst_t *L, void *datum, bool (*ptrFct)());

//Consulter la tête de la liste
struct lst_elm_t *getHead(struct lst_t list *L);

//Consulter la queue de la liste
struct lst_elm_t *getTail(struct lst_t *L);

//Consulter le nombre d'élément de la liste
int getNumelm(struct lst_t *L);

//Modifier le nombre d'élément de la liste
int setNumelm(struct lst_t *L, int numElm);

//Visualiser les éléments de la liste L grâce à la fonction pointé par ptrFct
void view_lst(struct lst_t *L, void (*prtFct)());

#endif
