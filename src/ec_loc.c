#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#include "ec_loc.h"

char *line_type_name[] = {
    "EMPTY",
    "NONE_EMPTY",
    "CODE_LINE",
    "FIRST_SLASH",
    "SINGLE_LINE",
    "MULTI_LINE_IN",
    "MULTI_LINE_IN_END",
    "MULTI_LINE"
};

void
Lines_Of_Code (char* filename)
{
    FILE* f = fopen(filename, "r");
    if (f != NULL)
    {
        char        c;
        int         lines           = 0;
        int         comment_lines   = 0;
        int         empty_lines     = 0;
        int         total_lines     = 0;
        LineType    line_type       = EMPTY;


        while ((c = fgetc(f)) != EOF)
        {
            if (DEBUG)
            {
                if (c != '\n')
                    printf ("%c", c);
            }

            if (c != '\n')
            {
                if (line_type == EMPTY)
                {
                    if  (!(c == ' ' || c == '{' || c == '}'))
                    {
                        if (c == '/')
                        {
                            line_type = FIRST_SLASH;
                        }
                        else
                        {
                            line_type = CODE_LINE;
                        }

                        continue;
                    }

                }

                if (line_type == FIRST_SLASH && c == '/')
                {
                    line_type = SINGLE_LINE;
                }
                else if (line_type == FIRST_SLASH && c == '*')
                {
                    line_type = MULTI_LINE_IN;
                }
                else if (line_type == FIRST_SLASH && c != '/')
                {
                    line_type = CODE_LINE;
                }
                else if (line_type == FIRST_SLASH && c != '*')
                {
                    line_type = EMPTY;
                }
                else if (line_type == MULTI_LINE_IN && c == '*')
                {
                    line_type = MULTI_LINE_IN_END;
                }
                else if (line_type == MULTI_LINE_IN_END && c != '/')
                {
                    line_type = MULTI_LINE_IN;
                }
                else if (line_type == MULTI_LINE_IN_END && c == '/')
                {
                    line_type = MULTI_LINE;
                }
            }
            else
            {
                if (DEBUG)
                {
                    printf (" <%s>\n", line_type_name[line_type]);
                }

                if (line_type == EMPTY)
                {
                    empty_lines++;
                }

                if (line_type == CODE_LINE)
                {
                    lines++;
                    line_type = EMPTY;
                }

                if (line_type == SINGLE_LINE)
                {
                    comment_lines++;
                    line_type = EMPTY;
                }
                else if (line_type == MULTI_LINE_IN)
                {
                    comment_lines++;
                }
                else if (line_type == MULTI_LINE_IN_END)
                {
                    comment_lines++;
                    line_type = MULTI_LINE_IN;
                }
                else if (line_type == MULTI_LINE)
                {
                    comment_lines++;
                    line_type = EMPTY;
                }

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
