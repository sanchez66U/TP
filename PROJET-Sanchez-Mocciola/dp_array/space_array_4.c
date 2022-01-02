#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "space_array.h"
#include "global.h"

void view_opt(const struct states_array_t *states)
{
	printf("OPT |\t");
	for (int bag = 0; bag < (states->Vmax + 1); bag += 1)
		printf("%2d\t", bag);
	printf("\n----|");
	for (int bag = 0; bag < (states->Vmax + 1); bag += 1)
		printf("--------");
	printf("\n");
	for (int obj = 0; obj < (states->num_obj + 1); obj += 1)
	{
		printf("%3d |\t", obj);
		for (int bag = 0; bag < (states->Vmax + 1); bag += 1)
		{
			int idx = obj * (states->Vmax + 1) + bag;
			if (states->OPT[idx] == INFTY)
				printf("INF\t");
			else if (states->OPT[idx] == UNDTR)
				printf("UND\t");
			else
				printf("%2d\t", states->OPT[idx]);
		}
		printf("\n");
	}
	printf("\n");
}