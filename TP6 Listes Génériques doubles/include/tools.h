#ifndef _CMP_
#define _CMP_

#include <stdbool.h>

/** is *a greater than *b */
bool gt_int(int *a, int *b);
bool gt_double(double *x, double *y);
bool gt_string(char *s1, char *s2);

/** less than stuff */
bool lt_int(int *a, int *b);
bool lt_double(double *x, double *y);
bool lt_string(char *s1, char *s2);

#endif
