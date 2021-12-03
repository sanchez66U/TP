#include <stdlib.h>	 // librairie standard
#include <stdio.h>	 // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h>	 // librairie d'assertions

#include "lst.h"
#include "lst_elm.h"
#include "outils.h"

void listehomoreelle();
void listehomoentiere();

int main()
{
	int v;
	struct lst_t *L = newLst();
	scanf("%d", &v);
	while (v > 0)
	{
		cons(L, v);
		scanf("%d", &v);
	}
	printLst(L);
	freeLst(L);
	return EXIT_SUCCESS;
}
void listehomoreelle()
{
	struct list *L = new_lst();
	double *v;
	do
	{
		double u;
		printf("Entrez un réel (0 pour s'arrêter): ");
		scanf("%lf", &u);
		if (u == 0)
			break;
		v = (double *)calloc(1, sizeof(double));
		*v = u;
		insert_ordered(&L, v, &cmpDouble);
	} while (true);
	view_lst(L, &printDouble);
	del_lst(&L, &rmDouble);
}
void listehomoentiere()
{
	struct list *L = newLst();
	int *v;
	do
	{
		int u;
		printf
			scanf if (u("Entrez un entier (0 pour s'arrêter): "); ("%d", &u);
					  == 0) break;
		v = (int *)calloc(1, sizeof(int));
		*v = u;
		insert_ordered(&L, v, &cmpInteger);
	} while (true);
	printLst(L, &printInteger);
	freeLst(&L, &rmInteger);
}
/*
int main() {
int cmpt, a = 8, b = 4, * ptra = &a, * ptrb = &b; double x = 5.4, y = 3.14, * ptrx = &x, * ptry = &y; struct list * L = consVide();
struct elmlist * iter;
cons(L, ptra); // un entier cons(L, ptrb); // un entier cons(L, ptrx); // un réel cons(L, ptry); // un réel
//La liste vaut [3.14 ; 5.4 ; 4 ; 8 ]
for (cmpt = 0, E = getHead(L); cmpt < getNumelm(L);
	 cmpt += 1, E = getSuc(E))
{
	if (cmpt < 2)
	{
		double *d = (double *)getData(E);
		printf("La valeur est réelle et vaut : %lf\n", *d);
	}
	else
	{
		int *d = (int *)getData(E);
		printf("La valeur est entière et vaut : %d\n", *d);
	}
}
return EXIT_SUCCESS;
}
*/