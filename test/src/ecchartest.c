#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#if 0
#include "ecchar.h"

int main()
{
  CharListPtr char_list = NULL;

  insert_char (&char_list, 'a', 1);
  insert_char (&char_list, 'i', 2);
  insert_char (&char_list, 'l', 2);
  insert_char (&char_list, 'm', 1);
  insert_char (&char_list, 'h', 5);
  insert_char (&char_list, 'a', 6);
  insert_char (&char_list, 't', 5);

  print_list (char_list);

  print_char (char_list, 6);

  char strarr[] = "malith Perera";

  CharListPtr char_list2 = NULL;
  init (&char_list2, strarr);

  print_list (char_list2);

  char strarr2[] = "Rohasha Malshi";

  CharListPtr char_list3 = Char_List (strarr2);

  print_list (char_list3);

  return 0;
}
#endif
