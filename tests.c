#include "intarith.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static ia_double
vector_normalize(size_t n, double *v)
{
  ia_double sum = dtoia(0);
  for (size_t i = 0; i < n; ++i)
  {
    sum = ia_add(sum, ia_mul(dtoia(v[i]), dtoia(v[i])));
  }

  ia_double norm = ia_sqrt(sum);
  for (size_t i = 0; i < n; ++i)
  {
    v[i] = ia_div(dtoia(v[i]), norm).n;
  }

  norm = dtoia(0.0);
  sum = dtoia(0.0);
  for (size_t i = 0; i < n; ++i)
  {
    sum = ia_add(sum, ia_mul(dtoia(v[i]), dtoia(v[i])));
  }

  norm = ia_sqrt(sum);

  return norm;
}

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
    printf("[pass] %f <= %f <= %f, fpe = %.16f\n\n",
        pie.min, pie.n, pie.max, ia_err(pie));
  }
  else
  {
    ia_print(pie);
    printf("[err] inequality min < n < max does not hold true");
    return 1;
  }

  printf("[working] normalizing vector\n");
  srand(0);
  double vect[1000];

  for (size_t i = 0; i < 1000; ++i)
  {
    vect[i] = rand();
  }

  ia_double normalized_vector_norm = vector_normalize(1000, vect);
  printf("[result] ");
  ia_print(normalized_vector_norm);

  if (1.0 - normalized_vector_norm.n <= 1e-14)
  {
    printf("[pass] norm == 1 with precision >= 1e-14\n\n");
  }
  else
  {
    printf("[err] norm != 1\n");
    return 1;
  }

  printf("[working] computing sqrt(2) to machine precision\n");
  ia_double sqrt_two = ia_sqrt(dtoia(2.0));
  printf("[result] ");
  ia_print(sqrt_two);

  if (1.4142135623730950 - sqrt_two.n <= 1e-16)
  {
    printf("[pass] %f is sqrt(2) computed to machine precision\n",
        sqrt_two.n);
  }
  else
  {
    printf("[err] %f is not at machine precision\n", sqrt_two.n);
  }


  return 0;
}
