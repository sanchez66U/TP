#ifndef _OUTILS_
#define _OUTILS_

#include <stdbool.h>

/** Fonctions :
- D'affichage d'une valeur entière,
- De suppression d'une mémoire de type entier,
- De comparaison de 2 entiers.
 */
void printInteger(int *i);
void freeInteger(int *i);
bool int_cmp(int *i, int *j);

/** Fonctions :
- D'affichage d'une valeur réelle,
- De suppression d'une mémoire de type réel,
- De comparaison de 2 réels.
 */
void double_print(double *d);
void double_rm(double *d);
bool double_cmp(double *u, double *v);

#endif // _OUTILS_
