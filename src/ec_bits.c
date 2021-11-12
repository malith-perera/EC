#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <memory.h>

enum
{
  EMPTY = 0,
  ONE = 1<<1,
  TWO = 1<<2,
  THREE = 1<<3,
  FOUR = 1<<4,
  FIVE = 1<<5
};


#define mask (FIVE|ONE)



void
display_bits
(
  unsigned value
)
{
  unsigned c;

  unsigned display_mask = 1 << 31;

  printf ("%u\n", value);

  for (c = 1; c <= 32; c++)
  {
    putchar (value & display_mask ? '1': '0');
    value <<= 1;

    if (c % 8 == 0)
    {
      putchar (' ');
    }
  }
  putchar ('\n');
}

#if 0
int  main ()
{
  unsigned a;

  memset (&a, 0, sizeof(unsigned));

  a = FIVE;

  if (a == FIVE) {
    printf ("yes");
  }

  display_bits (a);
  return 0;
}

#endif


