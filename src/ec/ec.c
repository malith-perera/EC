#include <stdio.h>
#include <errno.h> 
#include <sys/utsname.h> 

#include "ec.h"
#include "ec_version.h"
#include "ec_todo.h"
#include "ec_user.h"
#include "ec_dependency.h"


void
Create_Main_Files(char *argv[], char *path)
{
	char main_file[512];
	char path_file[512];
    FILE *fptr;

	if(strcmp(argv[1], "app") == 0 )
    {
		sprintf(main_file, 
			"#include \"%s.h\"\n\n"
			"int\nmain(int argc, char *argv[])\n"
			"{\n"
			"	printf(\"Hello World!\\n\");\n"
			"	printf(\"%s is running.\\n\");\n\n"
			"	return 0;\n"
			"}\n", argv[2], argv[2]);
	}

    // File pointer
	sprintf(path_file, "%s%s%s%s", path, "src/", argv[2], ".c");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL)
    {
        printf("Error: Cannot create app.c file\n");
    }
    else
    {
        fprintf(fptr, "%s", main_file);
        fclose(fptr);
    }
}


void
Create_Header_Files(char *argv[], char *path)
{
	char header_file[512];
	char path_file[512];
    FILE *fptr; //File pointer

	sprintf(header_file, 
		"#ifndef %s_H\n"
		"#define %s_H\n\n"
		"#include \"ec.h\"\n"
		"#include \"%s_version.h\"\n\n"
		"#endif // %s_H\n"
		, argv[2], argv[2], argv[2], argv[2]);

	sprintf(path_file, "%s%s%s%s", path, "src/", argv[2], ".h");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL)
    {
        printf("Error: Cannot create app.h file\n");
    }
    else
    {
        fprintf(fptr, "%s", header_file);
        fclose(fptr);
    }
}


void
EC_Make_Sh_Create(char *argv[], char *path)
{
	char app_name[32];
	char lib_name[32];
	char dir[4];
	char ec_make_sh[2048];  
	char command[512];
	char path_file[256];
    FILE *fptr;

    char app_text[256] = "";
    char lib_text[256] = "";
    char text_sh[512] = "";
    char app_remove_text[256] = "";
    char lib_remove_text[256] = "";
    char remove_text_sh[512] = "";

    if (strcmp(argv[1], "app") == 0 || strcmp(argv[1], "applib") == 0 )
    {
        strcpy(app_name, argv[2]);

        sprintf(app_text, 
            "if [ -f .ec/build/%s ]\n"
            "then\n"
            "  cp -f .ec/build/%s %s\n"
            "  ln -sf ../EC/ec ec\n"
            "else\n"
            "  echo 'Error: Unable to build'\n" 
            "fi\n", app_name, app_name, app_name);

        sprintf(app_remove_text,
            "if [ -f .ec/build/%s ]\n"
            "then\n"
            "  rm -f .ec/build/%s\n"
            "fi\n"
            "\n"
            "if [ -f %s ]\n"
            "then\n"
            "  rm -f %s\n"
            "fi\n", app_name, app_name, app_name, app_name);
    }

    if (strcmp(argv[1], "lib") == 0 || strcmp(argv[1], "applib") == 0)
    {
	    sprintf(lib_name, "%s%s%s", "lib", argv[2], ".so");

        sprintf(lib_text, 
            "if [ -f .ec/build/%s ]\n"
            "then\n"
            "  cp -f .ec/build/%s %s\n"
            "elso\n"
            "  echo 'Error: Unable to build\n'"
            "fi\n", lib_name, lib_name, lib_name);

        sprintf(lib_remove_text,
            "if [ -f .ec/build/%s ]\n"
            "then\n"
            "  rm -f .ec/build/%s\n"
            "fi\n"
            "\n"
            "if [ -f %s ]\n"
            "then\n"
            "  rm -f %s\n"
            "fi\n", lib_name, lib_name, lib_name, lib_name);
    }

    sprintf(text_sh, "%s%s", app_text, lib_text);
    sprintf(remove_text_sh, "%s%s", app_remove_text, lib_remove_text);

	sprintf(ec_make_sh, 
		"#!/bin/bash\n"
		"\n"
		"if [ ! -d .ec/build ]\n"
        "then\n"
        "  mkdir .ec/build\n"
		"fi\n"
		"\n"
        "%s"
		"\n"
        "cd .ec/build\n"
		"\n"
		"cmake -G \"Unix Makefiles\" -DCMAKE_BUILD_TYPE=Debug .. #Release #Debug\n"
		"\n"
		"make -j${nproc}\n"
		"\n"
        "cd ../..\n"
		"\n"
        "%s\n", remove_text_sh, text_sh);

	//printf("cmake %ld\n", strlen(cmake_file));

	sprintf(path_file, "%s/.ec/ec_make.sh", path);

    // File pointer

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if(fptr == NULL)
    {
        printf("Error: Cannot create ec_make.sh file\n");
        exit(1);
    }

    fprintf(fptr, "%s", ec_make_sh);

    fclose(fptr);

	sprintf(command, "%s%s", "sudo chmod a+x ", path_file);

	if(system(command) != 0)
    {
        printf ("system function failier\n");
        exit(EXIT_FAILURE); 
	}
}


void
EC_Run_Sh_Create(char *argv[], char *path)
{
	char name[128];
	char ec_run_sh[512];  
	char command[64];
	char path_file[32];
    FILE *fptr;

	if(strcmp(argv[1], "app") == 0)
    {
		strcpy(name, argv[2]);
	}
	
	sprintf(ec_run_sh, 
		"#!/bin/bash\n"
		"\n"
        "if [ -f %s ]\n"
        "then\n"
        "  echo 'Run %s ...'\n"
        "  echo\n"
        "  ./%s\n"
		"fi\n", argv[2], argv[2], argv[2]);

	//printf("cmake %ld\n", strlen(cmake_file));

	sprintf(path_file, "%s/.ec/ec_run.sh", path);

    // File pointer

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if(fptr == NULL)
    {
        printf("Error: Cannot create ec_make.sh file\n");
        exit(1);
    }

    fprintf(fptr, "%s", ec_run_sh);

    fclose(fptr);

	sprintf(command, "%s%s", "sudo chmod a+x ", path_file);

	if(system(command) != 0)
    {
        printf ("system function failier\n");
        exit(EXIT_FAILURE); 
	}
}


void
EC_Create_Remove_Todo_Tmp_Sh(char *argv[], char *path)
{
	char name[128];
	char dir[4];
	char ec_remove_todo_tmp_sh[128];  
	char command[512];
	char path_file[32];
    FILE *fptr;

	if(strcmp(argv[1], "app") == 0)
    {
		strcpy(dir, "bin");
		strcpy(name, argv[2]);
	}
	
	if(strcmp(argv[1], "lib") == 0)
    {
        return;
	}
	
	sprintf(ec_remove_todo_tmp_sh, 
		"#!/bin/bash\n"
		"\n"
		"if [ -f \".ec/todo.tmp\" ]; then\n"
        "rm .ec/todo.tmp\n"
		"fi\n");

	sprintf(path_file, "%s.ec/ec_remove_todo_tmp.sh", path);

    // File pointer

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if(fptr == NULL)
    {
        printf("Error: Cannot create ec_remove_todo_tmp.sh file\n");
        exit(1);
    }

    fprintf(fptr, "%s", ec_remove_todo_tmp_sh);

    fclose(fptr);

	sprintf(command, "sudo chmod a+x %s", path_file);

	if(system(command) != 0)
    {
        printf ("system function failier\n");
        exit(EXIT_FAILURE); 
	}
}


void
Create_App_CMake_File(char *app_name, char *path)
{
	char cmake_file[2048];  

	sprintf(cmake_file, 
		"cmake_minimum_required(VERSION 3.22)\n"
		"project(%s)\n"
		"\n"
		"set(CMAKE_BUILD_TYPE Debug)  #Debug #Release\n"
		"\n"
		"#selecting the build mode in their IDE\n"
		"if (${CMAKE_CXX_COMPILER_ID} STREQUAL \"GNU\" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL \"Clang\")\n"
		"    set (CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -ggdb3 -O0 --std=c11 -Wall -lm\")\n"
		"    set (CMAKE_CXX_FLAGS_DEBUG \"${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g\")\n"
		"    set (CMAKE_CXX_FLAGS_RELEASE \"${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2\")\n"
		"elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL \"MSVC\")\n"
		"    if (CMAKE_CXX_FLAGS MATCHES \"/W[0-4]\")\n"
		"        string(REGEX REPLACE \"/W[0-4]\" \"/W4\" CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS}\")\n"
		"    else ()\n"
		"        set (CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} /W4\")\n"
		"    endif ()\n"
		"endif ()\n"
		"\n"
		"get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)\n"
		"get_filename_component(PARENT2_DIR ${PARENT_DIR} DIRECTORY)\n"
		"\n"
		"#Set include directories\n"
		"set (PROJECT_INCLUDE_DIRS ${PARENT_DIR}/src ${PARENT_DIR}/include ${PARENT2_DIR}/EC/src \"/usr/local/include\")\n"
		"include_directories(${PROJECT_INCLUDE_DIRS})\n"
		"\n"
		"#Set link directories\n"
		"set (PROJECT_LINK_DIRS ${PARENT2_DIR}/EC)\n"
		"set (PROJECT_LINK_LIBS libEC.so)\n"
		"link_directories (${PROJECT_LINK_DIRS})\n"
		"\n"
		"#function file(GLOB...) allows for wildcard additions\n"
		"file(GLOB SOURCE_FILES \"${PARENT_DIR}/src/*.c\")\n"
		"\n"
		"#Generate executable from the sources\n"
		"add_executable(${PROJECT_NAME} ${SOURCE_FILES})\n"
		"target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS})\n"
		"\n"		
		"#message (\"${PROJECT_SOURCE_DIR}\")\n"
	, app_name);

	//printf("cmake %ld\n", strlen(cmake_file));

    // File pointer
    FILE *fptr;

	char path_file[256];

    sprintf(path_file, "%s.ec/CMakeLists.txt", path);

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL)
    {
        printf("Error: Cannot create app makefile\n");
        exit(1);
    }

    fprintf(fptr, "%s", cmake_file);
    fclose(fptr);
}


void
Create_Lib_CMake_File(char *argv[], char *path)
{
	char cmake_file[2048];  

	sprintf(cmake_file, 
		"cmake_minimum_required(VERSION 3.22)\n"
		"project(%s)\n"
		"\n"
		"set(CMAKE_BUILD_TYPE Debug)  #Debug #Release\n"
		"\n"
		"#selecting the build mode in their IDE\n"
		"if (${CMAKE_CXX_COMPILER_ID} STREQUAL \"GNU\" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL \"Clang\")\n"
		"    set (CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -ggdb3 -O0 --std=c11 -Wall -lm\")\n"
		"    set (CMAKE_CXX_FLAGS_DEBUG \"${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g\")\n"
		"    set (CMAKE_CXX_FLAGS_RELEASE \"${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2\")\n"
		"elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL \"MSVC\")\n"
		"    if (CMAKE_CXX_FLAGS MATCHES \"/W[0-4]\")\n"
		"        string(REGEX REPLACE \"/W[0-4]\" \"/W4\" CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS}\")\n"
		"    else ()\n"
		"        set (CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} /W4\")\n"
		"    endif ()\n"
		"endif ()\n"
		"\n"
		"get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)\n"
		"\n"
		"#Set include directories\n"
		"set (PROJECT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/include ${PARENT_DIR}/EC/src /usr/local/include)\n"
		"\n"
		"#Bring the .h header files into the project\n"
		"include_directories(${PROJECT_INCLUDE_DIRS})\n"
		"\n"
		"# file(GLOB...) for wildcard additions\n"
		"file(GLOB SOURCE_FILES \"${PROJECT_SOURCE_DIR}/src/*.c\")\n"
		"\n"
		"#Generate the shared library from the sources\n"
		"add_library(%s SHARED ${SOURCE_FILES})\n"
	, argv[2], argv[2]);

	//printf("cmake %ld\n", strlen(cmake_file));

    // File pointer
    FILE *fptr;

	char path_file[512];

	strcpy(path_file, path);
	strcat(path_file, "CMakeLists.txt");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL)
    {
        printf("Error: cannot create lib make file\n");
        exit(1);
    }

    fprintf(fptr, "%s", cmake_file);
    fclose(fptr);
}


void
EC_Create_App_Lib_Directories(char *argv[], char *path)
{
	char command[512];

	char *directories[2] = {"src", ".ec"}; 

	sprintf(command, "mkdir %s%s", path, argv[2]);

	if (system(command) != 0)
    {
		printf ("system function failier\n");
	}

	for(int i = 0; i < 2; i++)
    {
		sprintf(command, "%s%s%s%s%s", "mkdir ", path, argv[2], "/", directories[i]);

		if (system(command) != 0)
        {
			printf ("system function failier, cannot create directories\n");
		}
	}
}


void
EC_Copy_EC(char *argv[], char *app_path)
{
	char command[128];

    // Create a link for ec
	sprintf(command, "ln -sf ../EC/ec %sec", app_path);

    if(system(command) != 0)
    {
        printf ("system function failier. cannot create sympolic link to bin/ec\n");
        exit(EXIT_FAILURE); 
    }
}


void
EC_App(char *argv[], char *path)
{
	EC_Create_App_Lib_Directories(argv, path);

    char app_path[128] = {'\0'};

    sprintf(app_path, "%s%s/", path, argv[2]);

	EC_Make_Sh_Create(argv, app_path);
	Create_Main_Files(argv, app_path);
	Create_Header_Files(argv, app_path);
	Create_App_CMake_File(argv[2], app_path);
    EC_Todo_Create_File(argv, app_path);
	EC_Version_Update(argv, app_path);
    EC_Copy_EC(argv, app_path);
    EC_Run_Sh_Create(argv, app_path);
    EC_Create_Remove_Todo_Tmp_Sh(argv, app_path);
    EC_User_Create_File(app_path);
}


void
EC_Lib(char *argv[], char *path)
{
	EC_Create_App_Lib_Directories(argv, path);

    char app_path[128] = {'\0'};

	strcat(app_path, path);
	strcat(app_path, argv[2]);
	strcat(app_path, "/");

	EC_Make_Sh_Create(argv, app_path);
	Create_Header_Files(argv, app_path);
	Create_Lib_CMake_File(argv, app_path);
    EC_Todo_Create_File(argv, app_path);
	EC_Version_Update(argv, app_path);
    EC_Create_Remove_Todo_Tmp_Sh(argv, app_path);
    EC_User_Create_File(app_path);
}


void
EC_Make()
{
    if (system("sh ./.ec/ec_make.sh") == 0)
    {
        printf("\n");
        printf("[ Help: \"ec -h\" ] [ Change user: \"ec user -c\" ]\n"); 
    }
    else
    {
        printf ("system in EC_Make fail\n");
    }
}


void
EC_Run()
{
    if (system("sh ./.ec/ec_run.sh") != 0)
    {
        printf ("system in EC_Run failed\n");
    }
}


void
EC_Help()
{
    printf("ec [ -h = Help ] [ user = User info ] [ app = Create application ] [ lib = Create library ] [ todo = Todo list ] \n");
}


void
Argc_1(char *argv[], char *path)
{
    FILE *ec_user_file;
    char user_id[256];
    char user_name[128];
    int i = 0;
    int line = 1;
    char c;

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

    //if(system("lsb_release -ds") == 0); 

    // Open ec_user_local file
    ec_user_file = fopen("../EC/.ec/ec_user_local", "r");
        
    if(ec_user_file != NULL)
    {
        i = 0;
        while(line != 3)
        {
            if(line == 1)
            {
                if ( (c = fgetc(ec_user_file)) != '\n')
                {
                    user_name[i++] = c;
                }
                else
                {
                    user_name[i] = '\0';
                    line = 2;
                    i = 0;
                }
            }

            if(line == 2)
            {
                if ( (c = fgetc(ec_user_file)) != '\n')
                {
                    user_id[i++] = c;
                }
                else {
                    user_id[i] = '\0';
                    line = 3;
                }
            }
        }

        printf("User: %s ID: %s\n\n", user_name, user_id);

        fclose(ec_user_file);
    }
    else
    {
        if(EC_Check_Dependancy())
        {
            printf("\n");

            printf("---------------------\n");
            printf("| Welcome to be EC! |\n");
            printf("---------------------\n");

            printf("\n");

            EC_User_Add();
        }
        else {
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

    else if(strcmp(argv[1], "app") == 0)
    {
		printf("app name is missing\n");	
    }

    else if(strcmp(argv[1], "lib") == 0)
    {
		printf("lib name is missing\n");	
    }
    else if(strcmp(argv[1], "version") == 0)
    {
		EC_Version_Update(argv, path);
    }
    else if(strcmp(argv[1], "todo") == 0)
    {
		EC_Todo_Print_List(path);
    }
    else if(strcmp(argv[1], "ec_make.sh") == 0)
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
    else
    {
        printf("Unknown command\n");
    }
}


void
Argc_3(int argc, char *argv[], char *path)
{
	if(strcmp(argv[1], "app") == 0)
    {
		EC_App(argv, path);
    }
    else if(strcmp(argv[1], "lib") == 0)
    {
		EC_Lib(argv, path);
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
    else if(strcmp(argv[1], "todo") == 0 && argv[2][0] == '-')
    {
        EC_Todo_Append(argc, argv, path);
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "-a") == 0) 
    {
        EC_User_Add();
    }
    else if(strcmp(argv[1], "user") == 0 && strcmp(argv[2], "-c") == 0) 
    {
        EC_User_Change();
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
		EC_App(argv, path);
    }
    else if(strcmp(argv[1], "lib") == 0 && strcmp(argv[2], "-c") == 0)
    {
		EC_Lib(argv, path);
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
    else if(strcmp(argv[1], "todo") == 0 && argv[2][0] == '-') 
    {
        EC_Todo_Append(argc, argv, path);
    }
    else if(strcmp(argv[1], "todo") == 0)
    {
		EC_Todo_Print_List(path);
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


int
main(int argc, char *argv[])
{
   // int r = system("cat /etc/os-release"); 

	char path[128] = {'\0'};

	strcpy(path, "../");

	switch(argc) {
		case 1:
			Argc_1(argv, path);
			break;
		case 2:
			Argc_2(argc, argv, path);
			break;
		case 3:
			Argc_3(argc, argv, path);
			break;
		case 4:
			Argc_4(argc, argv, path);
			break;
		case 5:
			Argc_5(argc, argv, path);
			break;
		default:
            printf ("Too many amount of arguments\n");
			break;
	}

    //EC_Total_Lines_Of_Code("src", 'c');
    //EC_Total_Lines_Of_Code("src", 'h');

	return 0;
}
