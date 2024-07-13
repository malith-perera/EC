#include <stdio.h>
#include <errno.h> 
#include <sys/utsname.h> 

#include "ec.h"
#include "ec_version.h"
#include "ec_todo.h"
#include "ec_user.h"
#include "ec_dependency.h"


void
Create_Main_File(char *argv[], char *path)
{
	char main_file[512];
	char path_file[512];
    FILE *fptr;

	if(strcmp(argv[1], "app") == 0 )
    {
		sprintf(main_file, 
			"#include \"%s.h\"\n\n"
			"int\n"
            "main(int argc, char *argv[])\n"
			"{\n"
			"    printf(\"Hello World!\\n\");\n"
            "    Print_Message(\"%s\");\n"
            "\n"
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
Create_Header_File(char *argv[], char *path)
{
	char header_file[512];
	char path_file[512];
    FILE *fptr; //File pointer

	sprintf(header_file, 
		"#ifndef %s_H\n"
		"#define %s_H\n"
        "\n"
		"#include \"ec.h\"\n"
		"#include \"%s_version.h\"\n"
        "#include \"message.h\"\n"
        "\n"
		"#endif // %s_H\n"
		, argv[2], argv[2], argv[2], argv[2]);

	sprintf(path_file, "%s%s%s%s", path, "src/", argv[2], ".h");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr != NULL)
    {
        fprintf(fptr, "%s", header_file);
        fclose(fptr);
    }
    else
    {
        printf("Error: Cannot create app.h file\n");
    }
}


void
Create_Message_File(char *argv[], char *path)
{
	char app_msg_file[1024];
	char path_file[512];
    FILE *fptr;

	if(strcmp(argv[1], "app") == 0 )
    {
		sprintf(app_msg_file, 
			"#include \"message.h\"\n"
            "\n"
			"char* \n"
            "Set_Message(char msg[])\n"
			"{\n"
            "    sprintf(msg, \"%%s%%s\", msg, \" is running.\");\n" 
            "\n"
            "    return msg;\n"
			"}\n"
            "\n"
            "\n"
            "void\n"
            "Print_Message(char *msg)\n"
			"{\n"
            "    char message[64];\n"
            "    strcpy(message, msg);\n"
            "\n"
            "    printf(\"%%s\\n\", Set_Message(message));\n"
			"}\n");
	}

    // File pointer
	sprintf(path_file, "%s%s", path, "src/message.c");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL)
    {
        printf("Error: Cannot create app_message.c file\n");
    }
    else
    {
        fprintf(fptr, "%s", app_msg_file);
        fclose(fptr);
    }
}


void
Create_Message_Header_File(char *argv[], char *path)
{
	char msg_header_file[512];
	char path_file[512];
    FILE *fptr; //File pointer

	sprintf(msg_header_file, 
		"#ifndef MESSAGE_H\n"
		"#define MESSAGE_H\n"
        "\n"
		"#include \"ec.h\"\n"
        "#include \"%s.h\"\n"
		"#include \"%s_version.h\"\n"
        "\n"
        "\n"
        "char*\n"
        "Set_Message(char msg[]);\n"
        "\n"
        "\n"
        "void\n"
        "Print_Message(char *msg);\n"
        "\n"
		"#endif // MESSAGE_H\n"
		, argv[2], argv[2]);

	sprintf(path_file, "%s%s", path, "src/message.h");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr != NULL)
    {
        fprintf(fptr, "%s", msg_header_file);
        fclose(fptr);
    }
    else
    {
        printf("Error: Cannot create app.h file\n");
    }
}


void
Create_Test_Main_File(char *argv[], char *path)
{
	char main_test_file[2048];
	char path_file[512];
    FILE *fptr;

	if(strcmp(argv[1], "app") == 0 )
    {
		sprintf(main_test_file, 
			"#include \"message_test.h\"\n"
            "\n"
            "\n"
            "int\n"
            "main(int argc, char *argv[])\n"
            "{\n"
            "    int test_no;\n"
            "\n"
            "    EC_Test_Print_Header(\"Test: %s\");\n"
            "    printf(\"\\n\");\n"
            "\n"
            "    if(argc >= 2)\n"
            "    {\n"
            "        test_no = atoi(argv[1]);\n"
            "    }\n"
            "    else\n"
            "    {\n"
            "        printf(\"Select Test\\n\");\n"
            "        printf(\"-----------\\n\");\n"
            "        printf(\"Test: All           0\\n\");\n"
            "        printf(\"Test: Message       1\\n\");\n"
            "        printf(\"Test: Exit         -1\\n\");\n"
            "        printf(\"\\n\");\n"
            "\n"
            "        printf(\"Test : \");\n"
            "        scanf(\"%%d\", &test_no);\n"
            "        printf(\"\\n\");\n"
            "    }\n"
            "\n"
            "    // Exit\n"
            "    if(test_no == -1)\n"
            "    {\n"
            "        return 0;\n"
            "    }\n"
            "\n"
            "    if(test_no == 0)\n"
            "    {\n"
            "        printf(\"Run All Tests\\n\");\n"
            "        printf(\"-------------\\n\");\n"
            "    }\n"
            "\n"
            "    if(test_no == 1 || test_no == 0)\n"
            "    {\n"
            "        Test_Message();\n"
            "    }\n"
            "\n"
            "    EC_Error_Print_Msg(\"EC_Clean\", \"BEGIN\");\n"
            "    Clean();\n"
            "    EC_Test_Print_Msg(\"EC_Clean\", \"OK\", __LINE__);\n"
            "    EC_Error_Print_Msg(\"EC_Clean\", \"END\");\n"
            "\n"
            "    printf(\"\\n\");\n"
            "    printf(\"Test: %s Successful\\n\");\n"
            "\n"
            "    return 0;\n"
            "}\n", argv[2], argv[2]);
	}

    // File pointer
	sprintf(path_file, "%s%s%s%s", path, "tests/", argv[2], "_test.c");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL)
    {
        printf("Error: Cannot create app_test.c file\n");
    }
    else
    {
        fprintf(fptr, "%s", main_test_file);
        fclose(fptr);
    }
}

void
Create_Test_Header_File(char *argv[], char *path)
{
	char test_header_file[512];
	char path_file[512];
    FILE *fptr; //File pointer

	sprintf(test_header_file, 
		"#ifndef %s_TEST_H\n"
		"#define %s_TEST_H\n\n"
        "#include <assert.h>\n"
		"#include \"ec.h\"\n"
		"#include \"%s_version.h\"\n\n"
		"#endif // %s_TEST_H\n"
		, argv[2], argv[2], argv[2], argv[2]);

	sprintf(path_file, "%s%s%s%s", path, "tests/", argv[2], "_test.h");

    // open file in write mode
    fptr = fopen(path_file, "w");

    if (fptr != NULL)
    {
        fprintf(fptr, "%s", test_header_file);
        fclose(fptr);
    }
    else
    {
        printf("Error: Cannot create app_test.h file\n");
    }
}


void
Create_Message_Test_File(char *argv[], char *path)
{
	char msg_test_file[2048];
	char path_file[512];
    FILE *fptr;

	if(strcmp(argv[1], "app") == 0 )
    {
		sprintf(msg_test_file, 
			"#include \"%s_test.h\"\n"
			"#include \"message.h\"\n"
            "\n"
            "\n"
            "void\n"
            "Test_Set_Message()\n"
            "{\n"
            "    EC_Test_Print_Title(__func__, __FILE__);\n"
            "    EC_Test_Print_Subtitle(\"Test: Set_Message\");\n"
            "    EC_Error_Print_Msg(\"Test_Set_Message: \", \"BEGIN\");\n"
            "\n"
            "    char answer[64] = \"%s\";\n"
            "\n"
            "    strcpy(answer, Set_Message(answer));\n"
            "\n"
            "    assert(strcmp(answer, \"%s is running.\") == 0); // If answer is not equal assert function exit at here\n"
            "    \n"
            "    EC_Test_Print_Msg(\"Test: Set_Message\", \"OK\", __LINE__);\n"
            "\n"
            "    EC_Error_Print_Msg(\"Test_Set_Message: \", \"END\");\n"
            "}\n"
            "\n"
            "\n"
            "void\n"
            "Test_Message()\n"
            "{\n"
            "    EC_Test_Print_Header(\"Test: App.c\");\n"
            "\n"
            "    Test_Set_Message();\n"
            "    printf(\"\\n\");\n"
            "\n"
            "    EC_Error_Print_Msg(\"Test: App.c\", \"PASS\");\n"
            "}\n"
            , argv[2], argv[2], argv[2]);
	}

    // File pointer
	sprintf(path_file, "%s%s", path, "tests/message_test.c");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL)
    {
        printf("Error: Cannot create app_test.c file\n");
    }
    else
    {
        fprintf(fptr, "%s", msg_test_file);
        fclose(fptr);
    }
}


void
Create_Test_Message_Header_File(char *argv[], char *path)
{
	char test_msg_header_file[512];
	char path_file[512];
    FILE *fptr; //File pointer

	sprintf(test_msg_header_file, 
		"#ifndef %s_TEST_H\n"
		"#define %s_TEST_H\n\n"
		"#include \"ec.h\"\n"
		"#include \"%s_version.h\"\n\n"
        "\n"
        "void\n"
        "Test_Message();\n"
        "\n"
		"#endif // %s_TEST_H\n"
		, argv[2], argv[2], argv[2], argv[2]);

	sprintf(path_file, "%s%s", path, "tests/message_test.h");

    // open file in write mode
    fptr = fopen(path_file, "w");

    if (fptr != NULL)
    {
        fprintf(fptr, "%s", test_msg_header_file);
        fclose(fptr);
    }
    else
    {
        printf("Error: Cannot create app_test.h file\n");
    }
}


void
EC_Make_Sh_Create(char *argv[], char *path)
{
	char app_name[32];
	char lib_name[32];
	char dir[4];
	char make_sh[2048];  
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
            "if [ -f ../EC/ec ]\n"
            "then\n"
            "  ln -sf ../EC/ec ec\n"
            "fi\n"
            "\n"
            "if [ -f .ec/build/%s ]\n"
            "then\n"
            "  mv -f .ec/build/%s %s\n"
            "fi\n"
            "\n"
            "if [ -f .ec/build/test ]\n"
            "then\n"
            "  mv -f .ec/build/test test\n"
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
            "if [ -f ../EC/ec ]\n"
            "then\n"
            "  ln -sf ../EC/ec ec\n"
            "fi\n"
            "if [ -f .ec/build/%s ]\n"
            "then\n"
            "  mv -f .ec/build/%s %s\n"
            "fi\n"
            "if [ -f .ec/build/test ]\n"
            "then\n"
            "  mv -f .ec/build/test test\n"
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

	sprintf(make_sh, 
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

	sprintf(path_file, "%s/.ec/make.sh", path);

    // File pointer

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if(fptr == NULL)
    {
        printf("Error: Cannot create make.sh file\n");
        exit(1);
    }

    fprintf(fptr, "%s", make_sh);

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

	sprintf(path_file, "%s/.ec/run.sh", path);

    // File pointer

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if(fptr == NULL)
    {
        printf("Error: Cannot create make.sh file\n");
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
	char remove_todo_tmp_sh[128];  
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
	
	sprintf(remove_todo_tmp_sh, 
		"#!/bin/bash\n"
		"\n"
		"if [ -f \".ec/todo.tmp\" ]; then\n"
        "rm .ec/todo.tmp\n"
		"fi\n");

	sprintf(path_file, "%s.ec/remove_todo_tmp.sh", path);

    // File pointer

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if(fptr == NULL)
    {
        printf("Error: Cannot create remove_todo_tmp.sh file\n");
        exit(1);
    }

    fprintf(fptr, "%s", remove_todo_tmp_sh);

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
		"#include directories add .h headder files\n"
		"set (PROJECT_INCLUDE_DIRS ${PARENT_DIR}/src ${PARENT_DIR}/tests ${PARENT2_DIR}/EC/src/lib \"/usr/local/include\")\n"
		"include_directories(${PROJECT_INCLUDE_DIRS})\n"
		"\n"
		"#file(GLOB...) add .c source files\n"
		"file(GLOB SOURCE_FILES \"${PARENT_DIR}/src/*.c\")\n"
        "file(GLOB TEST_SOURCE_FILES \"${PARENT_DIR}/tests/*.c\")\n"
		"\n"
		"#Set libraries\n"
		"set (PROJECT_LINK_DIRS ${PARENT2_DIR}/EC)\n"
		"set (PROJECT_LINK_LIBS libEC.so)\n"
		"link_directories (${PROJECT_LINK_DIRS})\n"
		"\n"
		"#Generate executables\n"
		"add_executable(${PROJECT_NAME} ${SOURCE_FILES})\n"
        "list(FILTER SOURCE_FILES EXCLUDE REGEX \"%s.c\")\n"
        "add_executable(test ${TEST_SOURCE_FILES} ${SOURCE_FILES})\n"
		"\n"
        "#Link libraries\n"
		"target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${PROJECT_LINK_LIBS})\n"
		"target_link_libraries(test LINK_PUBLIC ${PROJECT_LINK_LIBS})\n"
		"\n"
		"#message (\"${PROJECT_SOURCE_DIR}\")\n"
        , app_name, app_name);

	//printf("cmake %ld\n", strlen(cmake_file));

    // File pointer
    FILE *fptr;

	char path_file[256];

    sprintf(path_file, "%s.ec/CMakeLists.txt", path);

    // Open file in write mode
    fptr = fopen(path_file, "w");

    // Exit when fail
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

	char *directories[3] = {"src", ".ec", "tests"}; 

	sprintf(command, "mkdir %s%s", path, argv[2]);

	if (system(command) != 0)
    {
		printf ("system function failier\n");
	}

	for(int i = 0; i < 3; i++)
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
    char app_path[128];

	EC_Create_App_Lib_Directories(argv, path);

    sprintf(app_path, "%s%s/", path, argv[2]);

	EC_Make_Sh_Create(argv, app_path);
	Create_Main_File(argv, app_path);
	Create_Header_File(argv, app_path);
    Create_Message_File(argv, app_path);
    Create_Message_Header_File(argv, app_path);
	Create_Test_Main_File(argv, app_path);
	Create_Test_Header_File(argv, app_path);
    Create_Message_Test_File(argv, app_path);
    Create_Test_Message_Header_File(argv, app_path);
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
    char lib_path[128];

	EC_Create_App_Lib_Directories(argv, path);

    sprintf(lib_path, "%s%s/", path, argv[2]);

	EC_Make_Sh_Create(argv, lib_path);
	Create_Header_File(argv, lib_path);
    Create_Message_Header_File(argv, lib_path);
	Create_Test_Main_File(argv, lib_path);
	Create_Test_Header_File(argv, lib_path);
    Create_Message_Test_File(argv, lib_path);
    Create_Test_Message_Header_File(argv, lib_path);
	Create_Lib_CMake_File(argv, lib_path);
    EC_Todo_Create_File(argv, lib_path);
	EC_Version_Update(argv, lib_path);
    EC_Create_Remove_Todo_Tmp_Sh(argv, lib_path);
    EC_User_Create_File(lib_path);
}


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

            printf("---------------------\n");
            printf("| Welcome to be EC! |\n");
            printf("---------------------\n");

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

    //EC_Total_Lines_Of_Code("src/ec", 'c');
    //EC_Total_Lines_Of_Code("src/ec", 'h');
    //EC_Total_Lines_Of_Code("src/lib", 'c');
    //EC_Total_Lines_Of_Code("src/lib", 'h');

	return 0;
}
