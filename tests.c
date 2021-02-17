#include "intarith.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Computes PI using Machin simple convergence formula.
 */
static ia_double
machin_simple_pie(size_t n)
{
  const ia_double sum_cof = dtoia(+4.0);
  const ia_double neg_one = dtoia(-1.0);
  const ia_double pos_one = dtoia(+1.0);

  ia_double sum = dtoia(+0.0);

  for (size_t i = 1; i <= n; ++i)
  {
    ia_double d = ia_sub(pos_one, ia_mul(dtoia(2), dtoia(i)));
    if (i % 2 == 0)
    {
      sum = ia_add(sum, ia_div(pos_one, d));
    }
    else
    {
      sum = ia_add(sum, ia_div(neg_one, d));
    }
  }

  return ia_mul(sum_cof, sum);
}


int
main(int argc, char **argv)
{
  printf("[working] computing pie to 500000 iterations ...\n");

  ia_double pie = machin_simple_pie(500000);
  printf("[result] ");
  ia_print(pie);

  if (pie.min <= pie.n &&
      pie.n <= pie.max)
  {
    printf("[pass] %f <= %f <= %f, fpe = %.16f\n",
        pie.min, pie.n, pie.max, ia_err(pie));
  }
  else
  {
    ia_print(pie);
    printf("[fail] inequality min < n < max does not hold true");
    return 1;
  }

  return 0;
}
