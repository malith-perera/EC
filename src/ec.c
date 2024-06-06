#include <stdio.h>
#include "ec.h"
#include <errno.h> 
#include <sys/utsname.h> 

#include "version.h"


void
Create_Main_Files(char *argv[], char *path)
{
	char main_file[256];

	char *app_name = argv[2]; 

	if(strcmp(argv[1], "app") == 0 ) {
		sprintf(main_file, 
			"#include \"%s.h\"\n\n"
			"int\nmain(int argc, char *argv[])\n"
			"{\n"
			"  printf(\"Hello world!\\n\");\n"
			"  printf(\"%s is working\\n\");\n\n"
			"  return 0;\n"
			"}\n", app_name, app_name);
	}

	if(strcmp(argv[1], "lib") == 0 ) {
		sprintf(main_file, 
			"#include \"%s.h\"\n"
			, app_name);
	}

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
Create_Make_Sh_File(char *argv[], char *path)
{
	char name[128];
	char dir[4];
	char *type = argv[2];
	char ec_make_sh[512];  
	char command[256];

	if(strcmp(argv[1], "app") == 0) {
		strcpy(dir, "bin");
		strcpy(name, argv[2]);
	}
	
	if(strcmp(argv[1], "lib") == 0) {
		strcpy(dir, "lib");

		strcpy(name, "lib");
		strcat(name, argv[2]);
		strcat(name, ".so");
	}
	
	sprintf(ec_make_sh, 
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
		"  cp %s ../%s/\n"
		"  cd ..\n"
		"  rm -r build\n"
		"else\n"
		"  echo \"Error: cannot build\"\n"
		"fi\n", name, name, dir);

	//printf("cmake %ld\n", strlen(cmake_file));

    // File pointer
    FILE *fptr;

	char path_file[256];

	strcpy(path_file, path);
	strcat(path_file, "/ec_make.sh");

    // open file in write mode
    fptr = fopen(path_file, "w");

    // exiting program 
    if(fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%s", ec_make_sh);
    fclose(fptr);

	strcpy(command, "sudo chmod a+x ");
	strcat(command, path_file);

	if(system(command) != 0) {
        printf ("system function failier\n");
        exit(EXIT_FAILURE); 
	}
}


void
Create_App_CMake_File(char *app_name, char *path)
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
		"set (PROJECT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/include ${PARENT_DIR}/EC/include \"/usr/local/include\")\n"
		"include_directories(${PROJECT_INCLUDE_DIRS})\n"
		"\n"
		"set (PROJECT_LINK_DIRS ${PARENT_DIR}/EC/lib)\n"
		"set (PROJECT_LINK_LIBS libEC.so)\n"
		"link_directories (${PROJECT_LINK_DIRS})\n"
		"\n"
		"#However, the file(GLOB...) allows for wildcard additions\n"
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
Create_Lib_CMake_File(char *app_name, char *path)
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
		"set (PROJECT_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/include ${PARENT_DIR}/EC/include \"${PROJECT_SOURCE_DIR}/.ec\" \"/usr/local/include\")\n"
		"\n"
		"#Bring the .h header files into the project\n"
		"include_directories(${PROJECT_INCLUDE_DIRS})\n"
		"\n"
		"# file(GLOB...) for wildcard additions\n"
		"file(GLOB SOURCE_FILES \"${PROJECT_SOURCE_DIR}/src/*.c\")\n"
		"\n"
		"#Generate the shared library from the sources\n"
		"add_library(%s SHARED ${SOURCE_FILES})\n"
	, app_name, app_name);

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
EC_App(char *argv[])
{
	char command[512];
	char path[256];

	strcpy(path, "");

	if(strcmp(argv[0], "./bin/ec") == 0) { // cwd in the EC directory
		strcat(path, "../");
	}
	else if(strcmp(argv[0], "./ec") == 0) { // cwd in the EC/bin directory
		strcat(path, "../../");
	}

	char *directories[5] = {"bin", "lib", "include", "src", ".ec"}; 

	strcpy(command, "");
	strcat(command, "mkdir ");
	strcat(command, path);
	strcat(command, argv[2]);

	if (system(command) != 0) {
		printf ("system function failier\n");
	}

	strcat(command, "/");

	for(int i = 0; i < 5; i++) {
		if(strcmp(argv[1], "app") == 0 && i == 1) continue;

		strcpy(command, "");
		strcat(command, "mkdir ");
		strcat(command, path);
		strcat(command, argv[2]);
		strcat(command, "/");
		strcat(command, directories[i]);

		if (system(command) != 0) {
			printf ("system function failier cannot create directories\n");
		}
	}

	strcat(path, argv[2]);
	strcat(path, "/");

	Create_Make_Sh_File(argv, path);
	Create_Main_Files(argv, path);
	Create_Header_Files(argv[2], path);
	Create_App_CMake_File(argv[2], path);
}


void
EC_Lib(char *argv[])
{
	char command[512];
	char path[256];

	strcpy(path, "");

	if(strcmp(argv[0], "./bin/ec") == 0) { // cwd in the EC directory
		strcat(path, "../");
	}
	else if(strcmp(argv[0], "./ec") == 0) { // cwd in the EC/bin directory
		strcat(path, "../../");
	}

	char *directories[5] = {"bin", "lib", "include", "src", ".ec"}; 

	strcpy(command, "");
	strcat(command, "mkdir ");
	strcat(command, path);
	strcat(command, argv[2]);

	if (system(command) != 0) {
		printf ("system function failier\n");
	}

	strcat(command, "/");

	for(int i = 0; i < 5; i++) {
		if(strcmp(argv[1], "lib") == 0 && i == 0) continue;
		strcpy(command, "");
		strcat(command, "mkdir ");
		strcat(command, path);
		strcat(command, argv[2]);
		strcat(command, "/");
		strcat(command, directories[i]);

		if (system(command) != 0) {
			printf ("system function failier\n");
		}
	}

	strcat(path, argv[2]);
	strcat(path, "/");
	Create_Make_Sh_File(argv, path);
	Create_Main_Files(argv, path);
	Create_Header_Files(argv[2], path);
	Create_Lib_CMake_File(argv[2], path);
}


void
EC_Make()
{
		if (system("sh ec_make.sh") != 0) {
			printf ("system in EC_Make fail\n");
		}
}


void
Argc_1(char *argv[])
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

	char filepath[256];

	strcpy(filepath, "");

	if(strcmp(argv[0], "./bin/ec") == 0) { // cwd in the EC directory
		strcat(filepath, "../");
	}
	else if(strcmp(argv[0], "./ec") == 0) { // cwd in the EC/bin directory
		strcat(filepath, "../../");
	}

	strcat(filepath, "ec_make.sh");

	// if ec_make.sh exist run it
	FILE *file;
    if((file = fopen(filepath,"r"))!=NULL)
    {
        fclose(file);
		EC_Make();
    }

}


void
Argc_2(char *argv[])
{
	if(strcmp(argv[1], "--version") == 0)
		printf( "EC %d.%d.%d.%d\n", VERSION, VERSION_YEARS, VERSION_MONTHS, VERSION_DAYS);

	if(strcmp(argv[1], "app") == 0)
		printf("app name is missing\n");	

	if(strcmp(argv[1], "lib") == 0)
		printf("lib name is missing\n");	

	if(strcmp(argv[1], "version") == 0)
		EC_Version_Update();

	if(strcmp(argv[1], "ec_make.sh") == 0)
		EC_Make();
}


void
Argc_3(char *argv[])
{
	if(strcmp(argv[1], "app") == 0)
		EC_App(argv);

	if(strcmp(argv[1], "lib") == 0)
		EC_Lib(argv);
}


int
main(int argc, char *argv[])
{
   // int r=system("cat /etc/os-release"); 

	switch(argc) {
		case 1:
			Argc_1(argv);
			break;
		case 2:
			Argc_2(argv);
			break;
		case 3:
			Argc_3(argv);
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
