#include "intervalarithmetic.h"

ia_double
dtoia(double d)
{
  ia_double ia;

  fesetround(FE_DOWNWARD);
  ia.min = d;

  fesetround(FE_UPWARD);
  ia.max = d;

  fesetenv(FE_DFL_ENV);
  ia.n = d;

  return ia;
}

ia_double
ia_add(ia_double a, ia_double b)
{
  ia_double res;
  fesetround(FE_DOWNWARD);
  res.min = a.min + b.min;

  fesetround(FE_UPWARD);
  res.max = a.max + b.max;

  fesetenv(FE_DFL_ENV);
  res.n = a.n + b.n;

  return res;
}

ia_double
ia_sub(ia_double a, ia_double b)
{
  ia_double res;
  fesetround(FE_DOWNWARD);
  res.min = a.min - b.max;

  fesetround(FE_UPWARD);
  res.max = a.max - b.min;

  fesetenv(FE_DFL_ENV);
  res.n = a.n - b.n;

  return res;
}

ia_double
ia_mul(ia_double a, ia_double b)
{
  ia_double res;
  if (a.min >= 0 && b.min >= 0)
  {
    fesetround(FE_DOWNWARD);
    res.min = a.min * b.min;

    fesetround(FE_UPWARD);
    res.max = a.max * b.max;

    fesetenv(FE_DFL_ENV);
    res.n = a.n * b.n;

    return res;
  }
  else
  {
    fesetround(FE_DOWNWARD);
    double min = a.min * b.min;
    if (a.min * b.max < min)
    {
      min = a.min * b.max;
    }
    else if (a.max * b.min < min)
    {
      min = a.max * b.min;
    }
    else if (a.max * b.max < min)
    {
      min = a.max * b.max;
    }
    res.min = min;

    fesetround(FE_UPWARD);
    double max = a.min * b.min;
    if (a.min * b.max > max)
    {
      max = a.min * b.max;
    }
    else if (a.max * b.min > max)
    {
      max = a.max * b.min;
    }
    else if (a.max * b.max > max)
    {
      max = a.max * b.max;
    }
    res.max = max;

    fesetenv(FE_DFL_ENV);
    res.n = a.n * b.n;

    return res;
  }
}

ia_double
ia_div(ia_double n, ia_double d)
{

  ia_double ret;

  if (d.min > 0 || d.max < 0)
  {
    fesetround(FE_DOWNWARD);
    ret.min = n.min/d.min;

    fesetround(FE_UPWARD);
    ret.max = n.max/d.max;

    fesetenv(FE_DFL_ENV);
    ret.n = n.n / d.n;
    return ret;
  }
  else if (d.min == 0)
  {
    fesetround(FE_DOWNWARD);
    ret.min = n.max / d.max;

    fesetround(FE_UPWARD);
    ret.max = INFINITY;

    fesetenv(FE_DFL_ENV);
    ret.n = n.n / d.n;

    return ret;
  }
  else if (d.max == 0)
  {
    fesetround(FE_DOWNWARD);
    ret.min = -INFINITY;

    fesetround(FE_UPWARD);
    ret.max = n.min / d.min;

    fesetenv(FE_DFL_ENV);
    ret.n = n.n / d.n;

    return ret;
  }
  else
  {
    // 0 is in the set 2 hard 4 now
    printf("warning: answer is non-trivial\n");
    exit(EXIT_FAILURE);
  }
}

double
ia_err(ia_double n)
{
  return (fabs(n.max - n.min));
}

void
ia_print(ia_double n)
{
  printf("%+.16f ∈ [%+.16f, %+.16f] err = %e\n", n.n, n.min, n.max,
      fabs(n.max - n.min));
}
