#include <stdio.h>
#include <time.h>
#include "ec_bench.h"

int bench_counter = 0;
Bench bench[2];

void start_bench (char *name, int loops)
{
  bench[bench_counter].name = name;
  bench[bench_counter].t1 = clock();
}


void end_bench ()
{
  bench[bench_counter].t2 = clock();
  bench_counter++;
}


void print_bench ()
{
  int i;

  for (i = 0; i < 2; i++)
  {
    if (bench[i].name)
    {
      float diff = ((float)(bench[i].t2  - bench[i].t1) / 1000000.0F ) * 1000;
      printf("%s : %f\n", bench[i].name, diff);
    }
  }
}
