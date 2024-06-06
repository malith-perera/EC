#include "ec_version.h"

void
EC_Version_New()
{
	char command[256];
	char path[512];

    strcpy(command, "mkdir .ec");
    if (system(command) != 0) {
        printf ("system function failier\n");
    }

    strcpy(command, "touch .ec/info");
    if (system(command) != 0) {
        printf ("system function failier\n");
        exit(EXIT_FAILURE); 
    }
}


void
EC_Version_Update()
{
    char sentence[512];

	sprintf(sentence, 
		"#ifndef VERSION_H\n"
		"#define VERSION_H\n\n"
		"#ifdef VERSION\n"
		"#undef VERSION\n"
		"#define VERSION %d\n"
		"#endif // VERSION\n\n"
		"#ifdef VERSION_YEARS\n"
		"#undef VERSION_YEARS\n"
		"#define VERSION_YEARS %d\n"
		"#endif // VERSION_YEARS\n\n"
		"#ifdef VERSION_MONTHS\n"
		"#undef VERSION_MONTHS\n"
		"#define VERSION_MONTHS %d\n"
		"#endif // VERSION_MONTHS\n\n"
		"#ifdef VERSION_DAYS\n"
		"#undef VERSION_DAYS\n"
		"#define VERSION_DAYS %d\n"
		"#endif // VERSION_DAYS\n\n"
		"#endif // VERSION_H\n", 1, 0, 0, 0);
    
    printf ("version.h lenght %ld", strlen(sentence));

    // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen(".ec/version.h", "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%s", sentence);
    fclose(fptr);
}
