#include <stdio.h>
#include <stdlib.h>
#include "ec_file.h"
#include "ec_error.h"

typedef struct ecfile {
	char *name;
	char *type;
	char *lines[];
} ecfile;



void
Lines_Of_Code (char* filename)
{
    FILE* f = fopen(filename, "r");
    if (f != NULL)
    {
        char c;
        int lines = 0;
        int comment_lines = 0;
        int empty_lines = 0;
        bool at_begining = true;
        int comment_line = 0;
        bool empty_line = true;
        int total_lines = 0;

        while ((c = fgetc(f)) != EOF)
        {
            if (c != '\n')
            {
                if (comment_line != 2)
                {
                    if (comment_line == 0 && c == '/')
                    {
                        comment_line = 1;
                    }
                    else if (comment_line == 1 && (c == '/' || c== '*'))
                    {
                        comment_line = 2;
                    }
                    else
                    {
                        comment_line = 0;
                    }

                    if (empty_line == true)
                    {
                        if  (c != ' ' && c != '{' && c != '}')
                        {
                            empty_line = false;
                        }
                    }
                }

                at_begining = false;
            }
            else
            {
                if (comment_line == 2)
                {
                    comment_lines++;
                }

                if (empty_line == true)
                {
                    empty_lines++;
                }

                if (comment_line != 2 && empty_line != true)
                {
                    lines++;
                }

                empty_line = true;
                comment_line = 0;
                at_begining = true;
                total_lines++;
            }
        }

        printf("Code lines    : %d\n", lines);
        printf("Comment lines : %d\n", comment_lines);
        printf("Empty lines   : %d\n", empty_lines);
        printf("Total lines   : %d\n", total_lines);

        fclose(f);
    }
    else
    {
        fprintf(stderr, "file not found\n");
    }
}

















void ecfile_ECFile_init ( ECFilePtr obj, char *file_name )
{
	obj->name = file_name;
}

void ecfile_ECFile_parse ( ECFilePtr obj )
{
	FILE *fPtr;
	char c;
	int counter = 0;

	if ( ( fPtr = fopen ( obj->name, "r" ) ) == NULL ) {
     		printf ( "File opening Error: %s file not found\n", obj->name );
		exit ( EXIT_SUCCESS );
	}
	else {
		while ( ( c = fgetc(fPtr ) ) != EOF ) {
			switch ( c ) {
				case '\n':
					printf ( "\n%d\n", counter );
					counter = 0;
			}
			printf ( "%c", c );
			counter++;
		}
#if 0
    while (fgets (line, sizeof (line), file) != NULL ) /* read a line */
    {
      fputs (line, stdout); /* write the line */

      /* get the first token */
      token = strtok (line, " ");

      col = 0;
      /* walk through other tokens */
      while (token != NULL) {
//        printf (" %s\n", token);
        map [row][col] =  atoi (token);
        token = strtok (NULL, " ");
        col++;
      }

      row++;
    }
#endif

		fclose(fPtr);
	}

}


void split ()
{
}





#include <stdio.h>
#include <string.h>
#include "ec_error.h"

// ECFile Methods

int line_counter = 0;

void
ec_read (EcFile *obj, char *file_name)
{
  FILE *fPtr;
  char c;
  int line_char = 0;

  obj->name = file_name;

  if ((fPtr = fopen (obj->name, "r")) == NULL) {
    //ec_error (FILE_ERROR, obj->name , 0, 0, "");
  }
  else {
    while ((c = fgetc(fPtr)) != EOF) {
      switch (c) {
        case '\n':
          obj->lines[line_counter].text[line_char] = '\0';
          obj->lines[line_counter].number = line_counter++;
          line_char = 0;
          break;
	default:
          obj->lines[line_counter].text[line_char] = c;
          line_char++;
      }
    }
    fclose (fPtr);
  }
}


void
ec_block (EcFile *obj) {
  int i = 0;
  int j = 0;
  int const indent;
  unsigned long pos;

  BlockType block = FILE_OBJECT;

  for (i = 0; i < line_counter; i++) {
    for (pos = 0; pos < (unsigned long) sizeof(obj->lines[i].text); pos++) {
      printf("%c", obj->lines[i].text[pos]);

   }
  }
}


// printf ("%c", obj->lines[i].text[j]);
/*      if (block == FILE_OBJECT && obj->lines[i].text[j] == '\n' && i == 0 && i == 0)
        break;

      if (block == FILE_OBJECT && isspace(obj->lines[i].text[j]))
        continue;
*/


