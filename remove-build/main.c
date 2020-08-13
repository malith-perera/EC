#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>


char app_dir[1024];
char subdr[1024];
char rmbuilddr[1024];

int main(void)
{
  struct dirent *de, *cde; // Pointer for directory entry

  /*
  if (system (NULL))
    printf ("Command Processor is present\n");
  else
    printf ("Command processor is not present\n");
    */

  // Change to upper directory
  chdir("..");

  // printing current working directory
  printf("%s\n", getcwd(app_dir, 1024));

  // opendir() returns a pointer of DIR type.
  DIR *dr = opendir(app_dir);

  if (dr == NULL) // opendir returns NULL if couldn't open directory
  {
    printf("Could not open current directory");
    return 0;
  }

  // for readdir()
  while ((de = readdir(dr)) != NULL)
  {
    if (!strcmp (de->d_name, ".") || !strcmp (de->d_name, ".."))
      continue;

    printf("%s\n", de->d_name);

    snprintf (subdr, sizeof(subdr), "%s/%s",app_dir, de->d_name);

    DIR *cdr = opendir(subdr);

    if (cdr == NULL) // opendir returns NULL if couldn't open directory
    {
      continue;
    }

    while ((cde = readdir (cdr)) != NULL)
    {
      if (!strcmp (cde->d_name, ".") || !strcmp (cde->d_name, ".."))
        continue;

      printf ("\t%s\n", cde->d_name);

      if (!strcmp (cde->d_name, "build"))
      {
        snprintf (rmbuilddr, sizeof (rmbuilddr), "bash -c 'rm -r %s/%s/build'", app_dir, de->d_name);
        system (rmbuilddr);
        printf ("build removed /home/malith/EC/%s/build\n", de->d_name);
        break;
      }
    }
  }

  closedir(dr);

  return 0;
}


//snprintf(cmd, sizeof(cmd), "gnome-terminal -- bash -c '%s; sleep 10; exec bash'", argv[1]);
