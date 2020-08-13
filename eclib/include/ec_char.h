typedef struct CharList
{
  char charactor;
  struct _CharList *nextPtr;
} CharList;

typedef CharList *CharListPtr;

CharListPtr
Char_List (char string[]);

void
init (CharListPtr *sPtr, char string[]);

void
insert_char (CharListPtr *sPtr, char charactor, int char_pos);

void
print_list (CharListPtr currentPtr);

void
print_char (CharListPtr currentPtr, int char_pos);
