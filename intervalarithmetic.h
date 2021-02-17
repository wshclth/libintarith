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

ia_double dtoia(double d);

ia_double ia_add(ia_double a, ia_double b);
ia_double ia_sub(ia_double a, ia_double b);
ia_double ia_mul(ia_double a, ia_double b);
ia_double ia_div(ia_double n, ia_double d);

void ia_print(ia_double n);

#endif
