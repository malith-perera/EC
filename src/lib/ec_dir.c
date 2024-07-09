#include "ec_dir.h"
#include <dirent.h>


void
EC_Dir_Get_Content(char *basePath)
{
    char dir_path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);

            // Construct new dir_path from our base dir_path
            strcpy(dir_path, basePath);
            strcat(dir_path, "/");
            strcat(dir_path, dp->d_name);

            //EC_Dir_Get_Content(dir_path);
        }
    }

    closedir(dir);
}
