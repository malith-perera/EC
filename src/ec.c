#include <stdio.h>
#include "ec.h"
#include <errno.h> 
#include <sys/utsname.h> 

#include "version.h"


void
Create_Main_Files(char *app_name, char *path)
{
	char main_file[256];  

	sprintf(main_file, 
		"#include <stdio.h>\n"
		"#include \"%s.h\"\n\n"
		"int\nmain(int argc, char *argv[])\n"
		"{\n"
		"  printf(\"Hello world!\\n\");\n"
		"  printf(\"%s is working\\n\");\n\n"
		"  return 0;\n"
		"}\n", app_name, app_name);

    // File pointer
    FILE *fptr;

	char path_file[256];

	strcpy(path_file, path);
	strcat(path_file, "src/");
	strcat(path_file, app_name);
	strcat(path_file, ".c");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%s", main_file);
    fclose(fptr);
}


void
Create_Header_Files(char *app_name, char *path)
{
	char header_file[256];  

	sprintf(header_file, 
		"#ifndef %s_H\n"
		"#define %s_H\n\n"
		"#include \"ec.h\"\n\n"
		"#endif // %s_H\n"
		, app_name, app_name, app_name);

    // File pointer
    FILE *fptr;

	char path_file[256];

	strcpy(path_file, path);
	strcat(path_file, "include/");
	strcat(path_file, app_name);
	strcat(path_file, ".h");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%s", header_file);
    fclose(fptr);
}


void
Create_Make_Sh_File(char *app_name, char *path)
{
	char make_sh[256];  
	char command[256];

	sprintf(make_sh, 
		"#!/bin/bash\n"
		"\n"
		"if [ -d \"build\" ]; then\n"
		"  rm -r build\n"
		"fi\n"
		"\n"
		"mkdir build\n"
		"cd build\n"
		"\n"
		"cmake -G \"Unix Makefiles\" -DCMAKE_BUILD_TYPE=Debug ../\n"
		"\n"
		"make -j${nproc}\n"
		"\n"
		"if [ -f \"%s\" ]; then\n"
		"  cp %s ../bin\n"
		"  cd ..\n"
		"  rm -r build\n"
		"else\n"
		"  echo \"Error: cannot build\"\n"
		"fi\n", app_name, app_name);

    // File pointer
    FILE *fptr;

	char path_file[256];

	strcpy(path_file, path);
	strcat(path_file, "/make.sh");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%s", make_sh);
    fclose(fptr);

	strcpy(command, "sudo chmod a+x ");
	strcat(command, path_file);

	if(system(command) != 0) {
        printf ("system function failier\n");
        exit(EXIT_FAILURE); 
	}
}

void
Create_CMake_File(char *app_name, char *path)
{
	char cmake_file[1536];  

	sprintf(cmake_file, 
		"cmake_minimum_required(VERSION 3.22)\n"
		"project(%s)\n"
		"\n"
		"set(CMAKE_BUILD_TYPE Debug)  #Debug #Release\n"
		"\n"
		"#selecting the build mode in their IDE\n"
		"if (${CMAKE_CXX_COMPILER_ID} STREQUAL \"GNU\" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL \"Clang\")\n"
		"    set (CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS}  `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c11 -Wall -lSDL2_image -lm\")\n"
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
		"set (PROJECT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/include ${PARENT_DIR}/EC/include \"/usr/local/include\")\n"
		"include_directories(${PROJECT_INCLUDE_DIRS})\n"
		"\n"
		"set (PROJECT_LINK_DIRS ${PARENT_DIR}/EC/lib)\n"
		"set (PROJECT_LINK_LIBS libEC.so)\n"
		"link_directories (${PROJECT_LINK_DIRS})\n"
		"\n"
		"#However, the file(GLOB...) allows for wildcard additions:\n"
		"file(GLOB SOURCE_FILES \"${PROJECT_SOURCE_DIR}/src/*.c\")\n"
		"\n"
		"add_executable(%s ${SOURCE_FILES})\n"
		"target_link_libraries(%s ${PROJECT_LINK_LIBS})\n"
	, app_name, app_name, app_name);

	//printf("cmake %ld\n", strlen(cmake_file));

    // File pointer
    FILE *fptr;

	char path_file[256];

	strcpy(path_file, path);
	strcat(path_file, "/CMakeLists.txt");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%s", cmake_file);
    fclose(fptr);
}

void
EC_App(char *arg[])
{
	char command[512];
	char path[256];

	strcpy(path, "");

	if(strcmp(arg[0], "./bin/ec") == 0) { // cwd in the EC directory
		strcat(path, "../");
	}
	else if(strcmp(arg[0], "./ec") == 0) { // cwd in the EC/bin directory
		strcat(path, "../../");
	}

	char *directories[5] = {"bin", "lib", "include", "src", ".ec"}; 

	strcpy(command, "");
	strcat(command, "mkdir ");
	strcat(command, path);
	strcat(command, arg[2]);

	if (system(command) != 0) {
		printf ("system function failier\n");
	}

	strcat(command, "/");

	for(int i = 0; i < 5; i++) {
		strcpy(command, "");
		strcat(command, "mkdir ");
		strcat(command, path);
		strcat(command, arg[2]);
		strcat(command, "/");
		strcat(command, directories[i]);

		if (system(command) != 0) {
			printf ("system function failier\n");
		}
	}

	strcat(path, arg[2]);
	strcat(path, "/");

	Create_Make_Sh_File(arg[2], path);
	Create_Main_Files(arg[2], path);
	Create_Header_Files(arg[2], path);
	Create_CMake_File(arg[2], path);
}


void
argc_1(char *arg[])
{
	struct utsname unm; 
	errno = 0; 

	if(uname(&unm) != 0) 
	{ 
		perror("Error: uname should return 0"); 
		exit(EXIT_FAILURE); 
	} 

	printf("EC %d.%d.%d.%d on ", VERSION, VERSION_YEARS, VERSION_MONTHS, VERSION_DAYS);
	printf("%s %s %s\n", unm.sysname, unm.release, unm.machine); 
	printf("Commands: 'help'\n\n");
}


void
argc_2(char *arg[])
{
	if(strcmp(arg[1], "--version") == 0)
		printf( "EC %d.%d.%d.%d\n", VERSION, VERSION_YEARS, VERSION_MONTHS, VERSION_DAYS);

	else if(strcmp(arg[1], "app") == 0)
		printf("app name is missing\n");	

	else if(strcmp(arg[1], "version") == 0)
		EC_Version_Update();
}


void
argc_3(char *arg[])
{
	if(strcmp(arg[1], "app") == 0)
		EC_App(arg);
}


int
main(int argc, char *arg[])
{
   // int r=system("cat /etc/os-release"); 

	switch(argc) {
		case 1:
			argc_1(arg);
			break;
		case 2:
			argc_2(arg);
			break;
		case 3:
			argc_3(arg);
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
	}

	return 0;
}
