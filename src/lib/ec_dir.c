#include "ec_dir.h"
#include <dirent.h>
#include <sys/stat.h>


EC_VAR_H(DirContent)
EC_VAR_C(DirContent)
EC_LIST_H(DirContent)
EC_LIST_C(DirContent)


time_t
EC_File_Modified_Time(const char *path_file)
{
    struct stat stat_buf;

    if (stat(path_file, &stat_buf) == -1)
    {
        perror(path_file);
        exit(1);
    }

    return stat_buf.st_mtime;
}


DirContentList *
EC_Dir_Get_Content(char *base_path)
{
    char dir_path[1000];
    struct dirent *dp;
    DIR *dir = opendir(base_path);

    DirContentList *dir_content_list = DirContent_List();

    // Unable to open directories
    if (!dir)
    {
        printf("Unable to open directory %s\n", base_path);
        return NULL;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);

            // Construct new dir_path from our base_path
            strcpy(dir_path, base_path);
            strcat(dir_path, "/");
            strcat(dir_path, dp->d_name);

            DirContent *name_dir_file = DirContent_New();
            strcpy(name_dir_file->dir_path, dir_path);
            strcpy(name_dir_file->name, dp->d_name);
            name_dir_file->modified_time = EC_File_Modified_Time(dir_path);
                
            DirContent_Append(dir_content_list, name_dir_file);

            EC_Dir_Get_Content(dir_path);
        }
    }

    closedir(dir);

    return dir_content_list;
}


bool
EC_Is_Dir(char *dir)
{
    struct stat stats;

    stat(dir, &stats);

    // Check for file existence
    if (S_ISDIR(stats.st_mode))
        return true;

    return false;
}
