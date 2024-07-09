#ifndef EC_USER_H
#define EC_USER_H

#include "ec.h"


typedef struct User {
    int  id;
    char name[128];
    char email[256];
    char compiler[32];
    char editor[32];
} User;


struct UserCurrent {
    int  id;
    char name[128];
};


typedef enum UserFileKey {
    EC_USER_NAME,
    EC_USER_ID,
    EC_USER_EMAIL,
    EC_USER_COMPILER,
    EC_USER_EDITOR,
    EC_USER_KEYS
} UserFileKey;


extern char *ec_user_file_key_names[EC_USER_KEYS];


typedef enum UserFileType {EC_USER_FILE, EC_USER_LOCAL_FILE, EC_USER_CURRENT_FILE} UserFileType;


void
EC_User_Create_File(char *app_path);


void
EC_User_Add(void);


void
EC_User_Change(void);


void
EC_User_Update_File(char *row_str, UserFileKey KEY, UserFileType file_type);


void
EC_User_Compiler(int argc, char *argv[], UserFileType file_type);


void
EC_User_Email(int argc, char *argv[], UserFileType file_type);


void
EC_User_Editor(int argc, char *argv[], UserFileType file_type);


void
EC_User_Print_File(UserFileType file_type);


#endif // EC_USER_H
