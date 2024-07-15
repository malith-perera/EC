#include <errno.h> 
#include <sys/utsname.h> 

#include "ec_cli.h"
#include "ec_user.h"
#include "ec_todo.h"
#include "ec_version.h"
#include "ec_dependency.h"
#include "ec_app_lib.h"


void
EC_Make()
{
    if (system("sh .ec/make.sh") == 0)
    {
        printf("\n");
        printf("[ Help: \"ec -h\" ] [ Change user: \"ec user -c\" ]\n"); 
    }
    else
    {
        printf ("System fail. make.sh error\n");
    }
}


void
EC_Run()
{
    if (system("sh .ec/run.sh") != 0)
    {
        printf ("system in EC_Run failed\n");
    }
}


void
EC_Total_Lines()
{
    EC_Total_Lines_Of_Code("src/ec", 'c');
    EC_Total_Lines_Of_Code("src/ec", 'h');
    EC_Total_Lines_Of_Code("src/lib", 'c');
    EC_Total_Lines_Of_Code("src/lib", 'h');
    EC_Total_Lines_Of_Code("include", 'h');
}


void
EC_Help()
{
    printf("ec [ -h = Help ] [ user = User info ] [ app = Create application ] [ lib = Create library ] [ todo = Todo list ] \n");
}


void
Argc_1(char *argv[], char *path)
{
    FILE  *ec_user_file;
    int    user_id;
    char   user_name[128];
    char   user_var[256];
    int    line = 1;
    char   c;
	struct utsname unm; 
	errno = 0; 

	if(uname(&unm) != 0)
    { 
		perror("Error: uname should return 0"); 
		exit(EXIT_FAILURE); 
	} 

	printf("EC %d.%d.%d on ", EC_VERSION_YEARS, EC_VERSION_MONTHS, EC_VERSION_ADD_FIX);
	printf("%s %s %s\n", unm.sysname, unm.release, unm.machine); 
    //printf("%s\n", unm.version);
    // int r = system("cat /etc/os-release"); 

    //if(system("lsb_release -ds") == 0); 

    // Open user file
    ec_user_file = fopen("../EC/.ec/user", "r");
        
    if(ec_user_file != NULL)
    {
        while(!feof(ec_user_file))
        {
            fscanf(ec_user_file, "%d\n%s\n%s\n%s\n%s\n\n,", &user_id, user_name, user_var, user_var, user_var);
        }

        printf("User: %s ID: %d\n\n", user_name, user_id);

        fclose(ec_user_file);
    }
    else
    {
        if(EC_Check_Dependancy())
        {
            printf("\n");

            printf("-------------------\n");
            printf("| Welcome! be EC! |\n");
            printf("-------------------\n");

            printf("\n");

            printf("Use:\n");
            printf("%-25s%s\n", "ec user -n", "New user");
            printf("%-25s%s\n", "ec user -a user_key", "User key");

            return;
        }
        else
        {
            printf("Dependency problem\n");
            return;
        }
    }

    EC_Make();
    EC_Run();
}


void
Argc_2(int argc, char *argv[], char *path)
{
	if(strcmp(argv[1], "--version") == 0)
    {
		printf( "EC %d.%d.%d\n", EC_VERSION_YEARS, EC_VERSION_MONTHS, EC_VERSION_ADD_FIX);
    }
    else if(strcmp(argv[1], "version") == 0)
    {
		EC_Version_Update(argv, path);
    }
    else if(strcmp(argv[1], "app") == 0)
    {
        App_Help();
    }
    else if(strcmp(argv[1], "lib") == 0)
    {
		Lib_Help();	
    }
    else if(strcmp(argv[1], "todo") == 0)
    {
		EC_Todo_Print_List(path);
    }
    else if(strcmp(argv[1], "make.sh") == 0)
    {
		EC_Make();
    }
    else if(strcmp(argv[1], "make") == 0) 
    {
        EC_Make();
    }
    else if(strcmp(argv[1], "-h") == 0) 
    {
        EC_Help();
    }
    else if(strcmp(argv[1], "user") == 0) 
    {
        EC_User_Print_File(EC_USER_CURRENT_FILE);
    }
    else if(strcmp(argv[1], "test") == 0) 
    {
        EC_Test("0");
    }
    else if(strcmp(argv[1], "lines") == 0) 
    {
        EC_Total_Lines();
    }
    else
    {
        printf("Unknown command\n");
    }
}


void
Argc_3(int argc, char *argv[], char *path)
{

    if(strcmp(argv[1], "app") == 0 && strcmp(argv[2], "-h") == 0)
    {
        App_Help();
    }
    else if(strcmp(argv[1], "lib") == 0 && strcmp(argv[2], "-h") == 0)
    {
		Lib_Help();	
    }
	else if(strcmp(argv[1], "app") == 0)
    {
		EC_Create_App(argv, path);
    }
    else if(strcmp(argv[1], "lib") == 0)
    {
		EC_Create_Lib(argv, path);
    }
    else if(strcmp(argv[1], "todo") == 0 && argv[2] == "-a")
    {
        EC_Todo_Append(argc, argv, path);
    }
    else if((strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-h") == 0 ))
    {
        EC_Todo_Help_Options();
    }
    else if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-l") == 0)
    {
		EC_Todo_Print_List(path);
    }
    else if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-t") == 0)
    {
        EC_Todo_Change_Title(argc, argv);
    }
    else if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-p") == 0)
    {
        EC_Todo_Help_Change_Position();
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "-n") == 0) 
    {
        EC_User_New(); // Add new user and output user key file
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "-k") == 0) 
    {
        EC_User_Key(); // Output a user key file according to current user
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "-a") == 0) 
    {
        EC_User_Add();
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "--compiler") == 0) 
    {
        EC_User_Compiler(argc, argv, EC_USER_LOCAL_FILE);
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "--email") == 0) 
    {
        EC_User_Email(argc, argv, EC_USER_LOCAL_FILE );
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "--editor") == 0) 
    {
        EC_User_Editor(argc, argv, EC_USER_LOCAL_FILE);
    }
    else if(strcmp(argv[1], "test") == 0 && strcmp(argv[2], "-h") == 0) 
    {
        EC_Test_Help();
    }
    else if(strcmp(argv[1], "test") == 0) 
    {
        EC_Test(argv[2]);
    }
    else
    {
        printf("Unknown command\n");
    }
}


void
Argc_4(int argc, char *argv[], char *path)
{
	if(strcmp(argv[1], "app") == 0 && strcmp(argv[2], "-c") == 0)
    {
		EC_Create_App(argv, path);
    }
    else if(strcmp(argv[1], "lib") == 0 && strcmp(argv[2], "-c") == 0)
    {
		EC_Create_Lib(argv, path);
    }
    else if(strcmp(argv[1], "todo") == 0 && argv[2] == "-a") 
    {
        EC_Todo_Append(argc, argv, path);
    }
    else if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-r") == 0)
    {
        EC_Todo_Remove(argv, argc, path);
    }
    else if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-s") == 0) // -s submit
    {
        EC_Todo_Remove(argv, argc, path);
    }
    else if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-l") == 0)
    {
        EC_Todo_Discription(argc, argv);
    }
    else if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-t") == 0)
    {
        EC_Todo_Change_Title(argc, argv);
    }
    else if(strcmp(argv[1], "todo") == 0)
    {
        EC_Todo_Change_Position(argv);
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "--compiler") == 0) 
    {
        EC_User_Compiler(argc, argv, EC_USER_LOCAL_FILE);
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "--email") == 0) 
    {
        EC_User_Email(argc, argv, EC_USER_LOCAL_FILE);
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "--editor") == 0) 
    {
        EC_User_Editor(argc, argv, EC_USER_LOCAL_FILE);
    }
    else
    {
        printf("Unknown command\n");
    }
}


void
Argc_5(int argc, char *argv[], char *path)
{
    if(strcmp(argv[1], "todo") == 0 && strcmp(argv[2], "-t") == 0)
    {
        EC_Todo_Change_Title(argc, argv);
    }
}
