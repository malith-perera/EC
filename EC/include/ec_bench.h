#ifndef EC_BENCH_H
#define EC_BENCH_H

int loop_counter;

void start_bench (char *name, int loops);
void end_bench ();
void print_bench ();

#define START_BENCH(name, loops)                                               \
  start_bench(name, loops);                                                    \
  for (loop_counter = 0; loop_counter < loops; loop_counter = loop_counter + 1)\
  {

#define END_BENCH() \
  }                 \
  end_bench ();

typedef struct Bench {
  char *name;
  clock_t t1;
  clock_t t2;
} Bench;

#endif
