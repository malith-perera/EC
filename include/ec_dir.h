#include "ec.h"

#ifndef EC_DIR
#define EC_DIR

typedef struct DirContent {
    long int modified_time;
    char dir_path[512];
    char name[256];
} DirContent;


//DirContentList *
//EC_Dir_Get_Content(char *base_path);


bool
EC_Is_Dir(char *dir);


#endif //EC_DIR
