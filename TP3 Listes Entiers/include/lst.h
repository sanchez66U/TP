#ifndef _LST_
#define _LST_

#include <stdlib.h>	 // librairie standard
#include <stdio.h>	 // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>	 // librairie d'assertions

struct lst_t
{
	struct lst_elm_t *head;
	struct lst_elm_t *tail;
	int numelm;
};

/** @brief Vérifier si la liste L est vide ou pas */
bool emptyLst(const struct lst_t *L);

/** @brief Construire une liste vide */
struct lst_t *newLst();

/** @brief Ajouter en tête de la liste L la donnée */
void cons(struct lst_t * L, void * datum);

/** @brief Visualiser les éléments de la liste L */
void printLst(struct lst_t *L);

/** @brief Libèrer la mémoire occupée par la liste */
void del_lst(struct lst_t ** ptrL, void (*ptrFct) ());

/** @brief Ajouter en queue de la liste L la donnée */
void queue(struct lst_t * L, void * datum);

/** @brief Insérer dans la liste L la donnée suivant l'ordre donné par la fonction pointée par ptrFct */ 
void insert_ordered(struct lst_t * L, void * datum, bool (*ptrFct) ());




/** @brief Consulter la tête de la liste */
struct lst_elm_t * getHead(struct list * L);
/** @brief Consulter la queue de la liste */
struct lst_elm_t * getTail(struct list * L);
/** @brief Consulter le nombre d'éléments rangés dans la liste */
int getNumelm(struct list * L);
/** @brief Modifier le nombre d'éléments rangés dans la liste */
int setNumelm(struct list * L, int numElm);
/** @brief Visualiser les éléments de la liste L grâce à la fonction pointée par ptrFct */
void view_lst(struct lst_t * L, void (*ptrFct) () );

#endif