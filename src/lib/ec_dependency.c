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


int
EC_Check_Dependancy()
{
    enum Compiler {GCC, CLANG, COMPILER_AMOUNT};
    char *compilers[COMPILER_AMOUNT] = {"gcc", "clang"};
    bool existing_compilers[COMPILER_AMOUNT] = {false, false};
    
    bool compiler_exist = false;
    bool cmake_exist = false;
    
    char selected_compiler[128];
    int n_compilers = 0;
    
    // Check existing compilers
    printf("Checking for supported compilers\n");

    // Check gcc exist
    existing_compilers[GCC] = EC_Dep_Check("gcc");

    // Check clang exist
    existing_compilers[CLANG] = EC_Dep_Check("clang");

    // Display existing compilers
    for(int i = 0; i < COMPILER_AMOUNT; i++) {
        if(existing_compilers[i] == true)
        {
            printf("%s found\n", compilers[i]); 
            strcpy(selected_compiler, compilers[i]);
            n_compilers++;
        }
    }

select_again:
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

        //EC_Strip(selected_compiler);

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
            goto select_again;
        }
    }
    else if (n_compilers == 1)
    {
        printf("Set %s as default compiler.\n", selected_compiler);
    }
    else
    {
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

    // Check cmake exist
    if(EC_Dep_Check("cmake"))
    {
        printf("cmake found\n");
    }
    else
    {
        printf("cmake not found. Please install cmake.\n");
    }
}
