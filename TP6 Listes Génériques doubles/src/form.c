#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tools.h"
#include "form.h"
#include "db.h"

void del_form(struct form *F)
{
  free(F);
}

struct form *read_form(FILE *fd, enum mode_t mode)
{
  assert(fd != NULL);

  struct form *F = (struct form *)calloc(1, sizeof(struct form));
  assert(F != NULL);

  if (mode == TEXT)
  {
    fscanf(fd, " %s", F->product);
    F->product[len_max - 1] = '\0';
    fscanf(fd, " %d", &(F->stock));
    fscanf(fd, " %lf", &(F->pbt));
  }
  else
  { // BINARY, or fd is a binary file
    fread(F, sizeof(struct form), 1, fd);
  }
  return F;
}

void write_form(struct form *F, enum mode_t mode, FILE *fd)
{
  assert(fd != NULL);

  if (mode == TEXT)
  {
#ifdef _DEBUG_
    printf("_DEBUG_--------------------view_form inside write_form\n");
    view_form(F);
#endif
    fprintf(fd, "%s\n", get_product(F));
    fprintf(fd, "%d\n", get_stock(F));
    fprintf(fd, "%lf\n", get_price(F));
  }
  else
  {
    fwrite(F, sizeof(struct form), 1, fd);
  }
}

char *get_product(struct form *F)
{
  assert(F != NULL);
  return F->product;
}

int get_stock(struct form *F)
{
  assert(F != NULL);
  return F->stock;
}

double get_price(struct form *F)
{
  assert(F != NULL);
  return F->pbt;
}

void view_form(struct form *F)
{
  assert(F != NULL);
  printf(
      "\t\tProduct form :\n\tProduct : %s\n\tStock : %d\n\tPrice before tax : %f\n",
      F->product, F->stock, F->pbt);
}

bool gt_form(struct form *F1, struct form *F2)
{
  assert(F1 != NULL && F2 != NULL);
  return gt_string(F1->product, F2->product);
}

bool lt_form(struct form *F1, struct form *F2)
{
  assert(F1 != NULL && F2 != NULL);
  return lt_string(F1->product, F2->product);
}
