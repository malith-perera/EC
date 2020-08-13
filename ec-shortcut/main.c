#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* argv[1] -> App name
 * argv[2] -> Exec full path
 * argv[3] -> Icon full path */

char *section1 = "\
[Desktop Entry]\n\
Encoding=UTF-8\n\
Version=1.0\n\
Type=Application\n\
Name=";

char *section3 = "\
StartupNotify=false\n\
StartupWMClass=\"Nautilus\"\n\
Terminal=false\n";

int main (int argc, char *argv[])
{
  FILE *file;
  char file_text[1024];
  char file_name[64];
  char chmod[128];

  if (argc >= 2)
  {
    snprintf (file_text, sizeof(file_text), "%s%s\nExec=%s\nIcon=%s\n%s", section1,
      argv[1], argv[2], argv[3], section3);
    snprintf (file_name, sizeof(file_name), "%s.desktop", argv[1]);
    printf ("%s", file_text);

    if ((file = fopen (file_name, "w")) == NULL)
    {
      printf ("file .desktop could not create");
    }
    else
    {
      fprintf (file, "%s", file_text);
      fclose (file);
      snprintf (chmod, sizeof(chmod), "chmod +x %s", file_name);
      system (chmod);
    }
  }

  return 0;
}
