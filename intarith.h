#ifndef INTERVAL_ARITHMETIC_H
#define INTERVAL_ARITHMETIC_H

/*
 * Expose FE_* to force IEEE rounding standard on the CPU
 */
#include <fenv.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
  /*
   * The possible minimum value in R inclusive that
   * represents n after arbitratry operations
   */
  double min;

  /*
   * The possible maximum value in R inclusive that
   * represents n after arbitrary operations
   */
  double max;

  /*
   * The result
   */
  double n;

} ia_double;

/* casts a double to an ia_double */
ia_double dtoia(double d);

/* a + b */
ia_double ia_add(ia_double a, ia_double b);

/* b - a */
ia_double ia_sub(ia_double a, ia_double b);

/* a * b */
ia_double ia_mul(ia_double a, ia_double b);

/* n / d */
ia_double ia_div(ia_double n, ia_double d);

/* sqrt(s) (Babylonian method) */
ia_double ia_sqrt(ia_double s);

/* gets the error present in the ia_double n */
double ia_err(ia_double n);

/* pretty prints the ia_double n */
void ia_print(ia_double n);

#endif
