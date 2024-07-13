#include "ec.h"
#include "ec_cli.h"


void
Total_Lines()
{
    EC_Total_Lines_Of_Code("src/ec", 'c');
    EC_Total_Lines_Of_Code("src/ec", 'h');
    EC_Total_Lines_Of_Code("src/lib", 'c');
    EC_Total_Lines_Of_Code("src/lib", 'h');
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

    //Total_Lines();

	return 0;
}
