#include "ec_dependency.h"

bool
EC_Dep_Check(char *app)
{
    char command[128];
    
    sprintf(command, "%s --version", app);

    if(system(command) == 0)
    {
        return true;
    }

    return false;
}


bool
EC_Check_Dependancy()
{
    enum Compiler {GCC, CLANG, COMPILER_AMOUNT};
    char *compilers[COMPILER_AMOUNT] = {"gcc", "clang"};
    bool existing_compilers[COMPILER_AMOUNT] = {false, false};
    
    bool compiler_exist = false;
    bool cmake_exist = false;
    
    char selected_compiler[128];
    int n_compilers = 0;

    FILE *fptr;
    
    // Check dependency check already
    fptr = fopen("../EC/.ec/deps", "r");

    if(fptr)
    {
        fclose(fptr);
        return true;
    }

    // Check existing compilers
    printf("\n");
    printf("Checking for supported compilers\n");
    printf("\n");

    // Check gcc exist
    existing_compilers[GCC] = EC_Dep_Check("gcc");
    
    if(existing_compilers[GCC])
    {
        printf("gcc found\n");
        n_compilers++;
    }
    else
    {
        printf("gcc not found\n");
    }

    printf("\n");

    // Check clang exist
    existing_compilers[CLANG] = EC_Dep_Check("clang");

    if(existing_compilers[CLANG])
    {
        printf("clang found\n");
        n_compilers++;
    }
    else
    {
        printf("clang not found\n");
    }

    printf("\n");

    SELECT_AGAIN:
    // if move than one compiler exist
    if(n_compilers > 1)
    {
        printf("Supported compilers: ");
        for(int i = 0; i < COMPILER_AMOUNT; i++) {
            if(existing_compilers[i] == true)
            {
                printf("%s ", compilers[i]); 
                if(i + 2 < COMPILER_AMOUNT)
                { 
                    printf("and ");
                }
                else
                {
                    printf(", ");
                }
            }
        }

        printf("\n");

        printf("Enter compiler: ");
        scanf("%s", selected_compiler);
        printf("\n");

        // Check entered compiler match
        EC_Strip(selected_compiler);

        for(int i = 0; i < COMPILER_AMOUNT; i++)
        {
            if(strcmp(selected_compiler, compilers[i]) == 0)
            {
                compiler_exist = true;
                break;
            }
        }

        if (compiler_exist)
        {
            printf("Set %s as default compiler.\n", selected_compiler);
        }
        else
        {
            printf("Unknown compiler. Please try again.\n");
            goto SELECT_AGAIN;
        }
    }
    else if (n_compilers == 1)
    {
        for(int i = 0; i < n_compilers; i++)
        {
            if(existing_compilers[i] == true)
            {
                strcpy(selected_compiler, compilers[i]);
            }

        }
        printf("Set %s as default compiler.\n", selected_compiler);
        compiler_exist = true;
    }
    else
    {
        printf("\n");
        printf("Compiler not found\n");
        printf("EC support ");
        for(int i = 0; i < COMPILER_AMOUNT; i++)
        {
            printf("%s ", compilers[i]);

            if (i + 2 < COMPILER_AMOUNT)
            {
                printf(", ");
            }
            else
            {
                printf(" and ");
            }
        }

        printf("\n");
        printf("Please install a compiler.\n");
    }

    printf("\n");

    // Check cmake exist
    if(EC_Dep_Check("cmake"))
    {
        printf("cmake found\n");
        cmake_exist = true;
    }
    else
    {
        printf("cmake not found. Please install cmake.\n");
    }

    if(compiler_exist && cmake_exist)
    {
        fptr = fopen("../EC/.ec/deps", "w");

        if(fptr)
        {
            fclose(fptr);
            return true;
        }
        else
        {
            printf("Unable to create deps file\n");
            return false;
        }
    }
}
