#include "intervalarithmetic.h"

#include <math.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
  ia_double pie = dtoia(0);
  ia_double cst = dtoia(0.1);

  for (size_t i = 0; i < 100; ++i)
  {
    pie = ia_add(pie, cst);
    ia_print(pie);
  }

  for (size_t i = 0; i < 99; ++i)
  {
    pie = ia_sub(pie, cst);
    ia_print(pie);
  }

  for (size_t i = 0; i < 10; ++i)
  {
    pie = ia_mul(pie, cst);
    ia_print(pie);
  }

  cst = dtoia(0);
  cst.max = 10;
  cst.min = -10;
  pie = ia_div(pie, cst);
  ia_print(pie);
}
