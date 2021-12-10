#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "tools.h"

bool gt_int(int *a, int *b)
{
  return (*a > *b);
}

bool gt_double(double *x, double *y)
{
  return (*x > *y);
}

bool gt_string(char *s1, char *s2)
{
  return strcmp(s1, s2) > 0;
}

bool lt_int(int *a, int *b)
{
  return (*a < *b);
}

bool lt_double(double *x, double *y)
{
  return (*x < *y);
}

bool lt_string(char *s1, char *s2)
{
  return strcmp(s1, s2) < 0;
}
