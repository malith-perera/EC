#include "ec_user.h"


char *ec_user_file_key_names[EC_USER_KEYS] = {"Id", "User", "Email", "Compiler", "Editor"};


void
EC_User_Create_File(char *app_path)
{
    FILE *fptr;
    char user_file[512];

    // Create user file
    sprintf(user_file, "%s/.ec/user", app_path);

    fptr = fopen(user_file, "w");

    if (fptr != NULL)
    {
        fclose(fptr);
        fptr = NULL;
    }
    else
    {
        printf("Error: Cannot create .ec/user file\n");
    }
}


void
EC_User_Add(void)
{
    FILE *ec_user_file_ptr;
    FILE *ec_user_local_file_ptr;
    FILE *ec_user_current_file_ptr;
    char new_lines[EC_USER_KEYS - 2];
    char user_name[128];
    int  user_id = 0;
    int  user_id_current = 0;
    int  i = 0;
    int  line = 0;
    char c;
    char answer[4];
    char line_info[256];
    struct UserCurrent user_current;
    User user;

    ec_user_local_file_ptr = fopen(".ec/user_local", "r");

    if(ec_user_local_file_ptr != NULL)
    {
        printf("You are in EC directory.\n");
        printf("Do you want to add as a EC core developer?\n");
        printf("You will be able to bug fix or add new things to EC\n");
        printf("Yes(y)/No(n)?");
        scanf("%s", answer);

        EC_Strip(answer);

        EC_String_To_Lower(answer);

        if (strcmp(answer, "n") == 0 || strcmp(answer, "no") == 0)
        {
            printf("Please move into your projects directory and use \"ec user -a\"\n");
        }
        else if(strcmp(answer, "y") == 0 || strcmp(answer, "yes") == 0)
        {
            ec_user_file_ptr = fopen("../EC/.ec/ec_user", "a");
            ec_user_local_file_ptr = fopen("../EC/.ec/ec_user_local", "r");
            ec_user_current_file_ptr = fopen("../EC/.ec/ec_user_current", "r");

            i = 0; 
            line = 1;

            // Get current User info
            while((c = fgetc(ec_user_current_file_ptr)) != EOF)
            {
                if(line == 1) 
                {
                    if (c != '\n')
                    {
                        line_info[i++] = c;
                    }
                    else
                    {
                        line_info[i] = '\0';
                        user_current.id = atoi(line_info);
                        i = 0;
                        line++;
                    }
                }
                else if (line == 2)
                {
                    if (c != '\n')
                    {
                        user_current.name[i++] = c;
                    }
                    else
                    {
                        user_current.name[i++] = '\n';
                        break;
                    }
                }
            }

            // Get user info from user_local file
            line = 1;
            i = 0;

            while((c = fgetc(ec_user_local_file_ptr)) != EOF)
            {
                if(line == 1)
                {
                    if (c != '\n')
                    {
                        line_info[i++] = c;
                    }
                    else
                    {
                        user_name[i] = '\0';
                        user.id = atoi(user_name);
                        i = 0;

                        if (user.id != user_current.id) // Neglect till next user
                        {
                            line = 1;
                            do {
                                c = fgetc(ec_user_local_file_ptr);

                                if (c == '\n')
                                {
                                    line++;
                                }
                            } while (i < (EC_USER_KEYS + 1) && c != EOF); // 1 for last empty line
                        }
                        else // Read user info
                        {
                            line = 2;

                            do {
                                c = fgetc(ec_user_local_file_ptr);

                                if (c != '\n')
                                {
                                    line_info[i++] = c;
                                }
                                else
                                {
                                    line_info[i] = '\0';

                                    if(line == 2)
                                    {
                                        strcpy(user.name, line_info);
                                    }
                                    if(line == 3)
                                    {
                                        strcpy(user.email, line_info);
                                    }
                                    if(line == 4)
                                    {
                                        strcpy(user.compiler, line_info);
                                    }
                                    if(line == 5)
                                    {
                                        strcpy(user.editor, line_info);
                                    }

                                    line++;
                                    i = 0;
                                }
                            }
                            while(line < EC_USER_KEYS && c != EOF);
                        }
                    }
                }
            }

            // Check user is already in the project
            // Append user to the project
        }
        else
        {
            printf ("Unknown option\n");
        }

        fclose(ec_user_file_ptr);
        fclose(ec_user_current_file_ptr);
        fclose(ec_user_local_file_ptr);
    }
    else
    {
        ec_user_file_ptr = fopen(".ec/ec_user", "a");

        if(ec_user_file_ptr != NULL)
        {
            printf("Enter user name: ");
            scanf("%s", user_name);

            // Set rand number as local id
            srand(time(NULL));

            while(user_id == 0)
            {
                user_id = rand();
                user_id = (user_id / 10) * 10 + 1;   // Set right most bit to 1 mean it's still a local id
            }

            strcpy(new_lines, ""); // Without strcpy strcat do not append '\0'

            i = 0;

            while(i < EC_USER_KEYS - 1) // adding space in user file for user data + empty last line 
            {
                strcat(new_lines, "\n");
                i++;
            }

            printf("\n");
            printf("New user added\n");
            printf("User name: %s\nLocal ID : %d\n\n", user_name, user_id);

            fprintf(ec_user_file_ptr, "%d\n%s\n%s", user_id, user_name, new_lines);

            fclose(ec_user_file_ptr);

            ec_user_file_ptr = NULL;

            ec_user_file_ptr = fopen("../EC/.ec/ec_user_current", "w");

            if(ec_user_file_ptr != NULL)
            {
                fprintf(ec_user_file_ptr, "%d\n%s", user_id, user_name);
                fclose(ec_user_file_ptr);
            }
            else
            {
                printf("Error: Unable to open ec_user_current file\n");
            }
        }
        else
        {
            printf("Please move into yor project directory and use \"ec user -a\"\n");
        }
    }

}


void
EC_User_Get_All()
{
    printf("Show All users\n");
    // Get all users from user_local file in EC/.ec
    //EC_Dir_Search("..", "");
    // Get all users from project applications beside to EC 
    // Append all none existing users to the user_local file
    // Display all users with a number
}


void
EC_User_Change(void)
{
    FILE *ec_user_file_ptr;
    char user_name[128];
    int  user_id = 0;
    int  user_number = 0;
    char c;
    int  i = 0;

    ec_user_file_ptr = fopen("../EC/.ec/ec_user_current", "r");

    printf("Current User:\n");

    if(ec_user_file_ptr)
    {
        i = 0;
        printf("%-6s : ", ec_user_file_key_names[i++]);

        while((c = fgetc(ec_user_file_ptr)) != EOF)
        {
            if(c != '\n')
            {
                printf("%c", c);
            }
            else
            {
                printf("\n");
                printf("%-6s : ", ec_user_file_key_names[i]);
                i++;
            }
        }

        printf("\n");

        EC_User_Get_All();

        printf("Enter user number: ");
        scanf("%d", &user_number);

        // Get current user id and name
        // Change user_current file
        
        printf("User changed\n");
        printf("User: %s\n", user_name);
        printf("Id  : %d\n", user_id);


        fclose(ec_user_file_ptr);
    }
}


void
EC_User_Update_File(char *row_str, UserFileKey KEY, UserFileType file_type)
{
    FILE *fptr, *fptr2;
    char c;
    char todo_str[256] = "";
    int i = 0;
    int current_todo_line = 1;

    if (file_type = EC_USER_FILE)
    {
        fptr = fopen("../EC/.ec/ec_user", "r");
        fptr2 = fopen("../EC/.ec/ec_user.tmp", "w");
    }
    else if (file_type == EC_USER_LOCAL_FILE)
    {
        fptr = fopen("../EC/.ec/ec_user_local", "r");
        fptr2 = fopen("../EC/.ec/ec_user_local.tmp", "w");
    }

    if (fptr != NULL && fptr2 != NULL)
    {
        while ((c = fgetc(fptr)) != EOF)
        {
            if(c != '\n')
            {
                todo_str[i++] = c;
            }
            else 
            {
                if(current_todo_line == KEY)
                {
                    strcpy(todo_str, row_str);
                }
                else
                {
                    todo_str[i++] = '\0';
                }

                fprintf(fptr2, "%s\n", todo_str);
                strcpy(todo_str, "");
                current_todo_line++;
                i = 0;
            }
        }

        fclose(fptr);
        fclose(fptr2);
    }
    else
    {
        printf("Error: ec_user cannot open write mode.\n");
    }

    if (file_type = EC_USER_FILE)
    {
        fptr = fopen("../EC/.ec/ec_user", "w");
        fptr2 = fopen("../EC/.ec/ec_user.tmp", "r");
    }
    else if (file_type == EC_USER_LOCAL_FILE)
    {
        fptr = fopen("../EC/.ec/ec_user_local", "w");
        fptr2 = fopen("../EC/.ec/ec_user_local.tmp", "r");
    }

    if (fptr != NULL && fptr2 != NULL)
    {
        while ((c = fgetc(fptr2)) != EOF)
        {
            fputc(c, fptr);
        }

        fclose(fptr);
        fclose(fptr2);
    }
    else
    {
        printf ("Error: could not update ec_user file\n");
    }
}


void
EC_User_Name(int argc, char *argv[], UserFileType file_type)
{
    char user_name[256];
    FILE *fptr;

    if(argc == 3)
    {
        printf("Name: ");
        scanf("%s", user_name);
        EC_User_Update_File(user_name, EC_USER_NAME, file_type);
    }
    else if (argc == 4)
    {
        strcpy(user_name, argv[3]);
        EC_User_Update_File(user_name, EC_USER_NAME, file_type);
    }
    else
    {
        printf("Cannot add user name to ec_user file. Unknown amount of arguments\n");
    }
}


void
EC_User_Compiler(int argc, char *argv[], UserFileType file_type)
{
    char user_compiler[256];
    FILE *fptr;

    if(argc == 3)
    {
        printf("Compiler: ");
        scanf("%s", user_compiler);
        EC_User_Update_File(user_compiler, EC_USER_COMPILER, file_type);
    }
    else if (argc == 4)
    {
        strcpy(user_compiler, argv[3]);
        EC_User_Update_File(user_compiler, EC_USER_COMPILER, file_type);
    }
    else
    {
        printf("Cannot add user compiler to ec_user file. Unknown amount of arguments\n");
    }
}


void
EC_User_Email(int argc, char *argv[], UserFileType file_type)
{
    char user_email[256];
    FILE *fptr;

    if(argc == 3)
    {
        printf("email: ");
        scanf("%s", user_email);
        EC_User_Update_File(user_email, EC_USER_EMAIL, file_type);
    }
    else if (argc == 4)
    {
        strcpy(user_email, argv[3]);
        EC_User_Update_File(user_email, EC_USER_EMAIL, file_type);
    }
    else
    {
        printf("Cannot add user email address to ec_user file. Unknown amount of arguments\n");
    }
}


void
EC_User_Editor(int argc, char *argv[], UserFileType file_type)
{
    char user_editor[64];
    FILE *fptr;

    if(argc == 3)
    {
        printf("Editor: ");
        scanf("%s", user_editor);
        EC_User_Update_File(user_editor, EC_USER_EDITOR, file_type);
    }
    else if (argc == 4)
    {
        strcpy(user_editor, argv[3]);
        EC_User_Update_File(user_editor, EC_USER_EDITOR, file_type);
    }
    else
    {
        printf("Cannot add user editor to ec_user file. Unknown amount of arguments\n");
    }
}


void
EC_User_Print_File(UserFileType file_type)
{
    FILE *fptr;
    char c;
    int i = 0;

    if(file_type == EC_USER_CURRENT_FILE)
    {
        fptr = fopen("../EC/.ec/ec_user_current", "r");
    }
    else
    {
        fptr = fopen("../EC/.ec/ec_user", "r");
    }

    printf("%-12s: ", ec_user_file_key_names[i++]); // Print ec_user_file first key

    if (fptr != NULL)
    {
        while ((c = fgetc(fptr)) != EOF)
        {
            printf("%c", c);

            if(c == '\n' && i < EC_USER_KEYS - 1)
            {
                printf("%-12s: ", ec_user_file_key_names[i++]);
            }
        }
        printf("\n");

        fclose(fptr);
    }
    else
    {
        printf("Error: cannot open ec_user file to print before change\n");
    }
}
