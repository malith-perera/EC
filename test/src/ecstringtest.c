#include <stdio.h>
#include <stdlib.h>
#if 0
#include "ecstring.h"

int main()
{
  char a[] = "one";
  char *b = "three";
  char *c = "two";
  char *d = "zero";
  char *e = "five";
  char *f = "six";
  char *g = "four";


  StrListPtr str_list = NULL;

  insert_line (&str_list, a, 1);
  insert_line (&str_list, b, 2);
  insert_line (&str_list, c, 2);
  insert_line (&str_list, d, 1);
  insert_line (&str_list, e, 5);
  insert_line (&str_list, f, 6);
  insert_line (&str_list, g, 5);

  print_list (str_list);

  print_line (str_list, 6);

  return 0;
}
#endif
