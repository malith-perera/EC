#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

char subdr[1024];
char subtdr[1024];
char rmbuilddr[1024];
char mkbuilddr[1024];

int main(void)
{
  char app_dir[1024];

  // using the command

  // printing current working directory
  printf("%s\n", getcwd(app_dir, 1024));

  /*struct dirent *de, *cde, *ctde; // Pointer for directory entry*/

  /*
  if (system (NULL))
    printf ("Command Processor is present\n");
  else
    printf ("Command processor is not present\n");
    */

  // opendir() returns a pointer of DIR type.
  /*DIR *dr = opendir("/home/malith/EC");*/

  /*if (dr == NULL) // opendir returns NULL if couldn't open directory*/
  /*{*/
    /*printf("Could not open current directory" );*/
    /*return 0;*/
  /*}*/

  /*// for readdir()*/
  /*while ((de = readdir(dr)) != NULL)*/
  /*{*/
    /*printf("%s\n", de->d_name);*/

    /*if (!strcmp (de->d_name, ".") || !strcmp (de->d_name, ".."))*/
      /*continue;*/


    /*snprintf (subdr, sizeof(subdr), "/home/malith/EC/%s", de->d_name);*/

    /*DIR *cdr = opendir(subdr);*/

    /*if (cdr == NULL) // opendir returns NULL if couldn't open directory*/
    /*{*/
      /*continue;*/
    /*}*/

    /*while ((cde = readdir(cdr)) != NULL)*/
    /*{*/
      /*if (!strcmp (cde->d_name, ".") || !strcmp (cde->d_name, ".."))*/
        /*continue;*/

      /*printf("\t%s\n", cde->d_name);*/

      /*if (!strcmp (cde->d_name, "tools"))*/
      /*{*/
        /*snprintf (subtdr, sizeof (subtdr), "/home/malith/EC/%s/%s", de->d_name, cde->d_name);*/
        /*printf ("tools found %s\n", subtdr);*/

        /*DIR *ctdr = opendir (subtdr);*/

        /*if (ctdr == NULL)*/
        /*{*/
          /*continue;*/
        /*}*/

        /*while ((ctde = readdir (ctdr)) != NULL)*/
        /*{*/
          /*if (!strcmp (ctde->d_name, ".") || !strcmp (ctde->d_name, ".."))*/
            /*continue;*/

          /*printf ("\t\t%s\n", ctde->d_name);*/

          /*if (!strcmp (ctde->d_name, "build"))*/
          /*{*/
            /*printf ("build found /home/malith/EC/%s/%s/build\n", de->d_name, cde->d_name);*/
            /*snprintf (rmbuilddr, sizeof (rmbuilddr), "bash -c 'rm -r /home/malith/EC/%s/%s/build'", de->d_name, cde->d_name);*/
            /*snprintf (mkbuilddr, sizeof (rmbuilddr), "bash -c 'mkdir /home/malith/EC/%s/%s/build'", de->d_name, cde->d_name);*/
            /*//snprintf(cmd, sizeof(cmd), "gnome-terminal -- bash -c '%s; sleep 10; exec bash'", argv[1]);*/
            /*system (rmbuilddr);*/
            /*system (mkbuilddr);*/
            /*break;*/
          /*}*/
        /*}*/

        /*closedir (ctdr);*/
      /*}*/
    /*}*/

    /*closedir(cdr);*/
  /*}*/

  /*closedir(dr);*/

  return 0;
}
