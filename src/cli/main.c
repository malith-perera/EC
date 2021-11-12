#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* still not handle unlimited number of arguments
 * can do it by calculate all argument lengths first and initialize a char array for that size
 * use ec.h to calculate argument lengths
 */

char cmd[1024];
char args[1024];

int
main (int argc, char *argv[])
{

  // Clean args array
  for (int i = 0; i < argc * 3; i ++)
  {
    args[i] = '\0';
  }

  // Clean cmd array
  for (int i = 0; i < 1024; i ++)
  {
    cmd[i] = '\0';
  }

  // Append %s to args for number of arguments
  for (int i = 1; i < argc; i++)
  {
    strcat (args, argv[i]);
    strcat (args, " ");
  }

  // Initial cmd text
  strcat (cmd, "gnome-terminal -- bash -c '");
  strcat (cmd, args);
  strcat (cmd, "; read var'");

  system (cmd);

  return 0;
}


/* sample snprintf
 * snprintf(cmd, sizeof(cmd), "gnome-terminal -- bash -c '%s; read var'", argv[i]);*/
