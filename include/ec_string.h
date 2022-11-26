#ifndef EC_STRING
#define EC_STRING

#ifndef EC_CONCAT
#define EC_CONCAT(x, y, z) x ## y ## z
#endif

#ifndef EC_CONCAT4
#define EC_CONCAT4(a, b, c, d) a ## b ## c  ## d
#endif

// Change all capital letters in to simple in an array
void
EC_Simplize(char word[]);

void
EC_Capitalize(char word[]);

struct _StrList
{
  char *line;
  struct _StrList *nextPtr;
};

typedef struct _StrList StrList;
typedef StrList * StrListPtr;

void
insert_line (StrListPtr *sPtr, char *line,  int line_no);

void
print_line (StrListPtr currentPtr, int line);

void
print_list (StrListPtr currentPtr);


#endif // EC_STRING
