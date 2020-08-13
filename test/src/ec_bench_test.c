#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "ec_bench.h"

struct student {
	char *name;
	int marks[8];
};


typedef struct student Student;


int marks[][8] = {
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78},
		{30, 40, 60, 80, 50, 99, 69, 78}
		};


char *names[] = {
		"Damith Anuhas1",
		"Damith Anuhas2",
		"Damith Anuhas3",
		"Damith Anuhas4",
		"Damith Anuhas5",
		"Damith Anuhas6",
		"Damith Anuhas7",
		"Damith Anuhas8",
		"Damith Anuhas9",
		"Damith Anuhas10",
		"Damith Anuhas11",
		"Damith Anuhas12",
		"Damith Anuhas13",
		"Damith Anuhas14",
		"Damith Anuhas15",
		"Damith Anuhas16",
		"Damith Anuhas17",
		"Damith Anuhas18",
		"Damith Anuhas19",
		"Damith Anuhas20",
		"Damith Anuhas21",
		"Damith Anuhas22",
		"Damith Anuhas23",
		"Damith Anuhas24",
		"Damith Anuhas25",
		"Damith Anuhas26",
		"Damith Anuhas27",
		"Damith Anuhas28",
		"Damith Anuhas29",
		"Damith Anuhas30",
		"Damith Anuhas31",
		"Damith Anuhas32",
		"Damith Anuhas33",
		"Damith Anuhas34",
		"Damith Anuhas35",
		"Damith Anuhas36",
		"Damith Anuhas37",
		"Damith Anuhas38",
		"Damith Anuhas39",
		"Damith Anuhas40"
};

#if 0
int main()
{

	int total = 0;

  int lmarks [40][8];
	char *lnames[40];

  START_BENCH("ARRAY_TEST", 1000);

	for ( int i=0; i < 40; i++ ) {
		lnames[i] = names[i];
		for ( int j=0; j < 8; j++ ) {
			lmarks[i][j] = marks[i][j];
		}
	}

	for( int i=0; i < 40; i++ ) {
		total = lmarks[i][0], lmarks[i][1], lmarks[i][2], lmarks[i][3], lmarks[i][4], lmarks[i][5], lmarks[i][6], lmarks[i][7];
		printf("Name: %s subject marks : %d %d %d %d %d %d %d %d Total: %d\n", lnames[i], lmarks[i][0], lmarks[i][1], lmarks[i][2], lmarks[i][3], lmarks[i][4], lmarks[i][5], lmarks[i][6], lmarks[i][7], total);
		total = 0;
	}

  END_BENCH();

  START_BENCH("OBJECT_TEST", 1000);

	Student s[40];

	for ( int i=0; i < 40; i++ ) {
		s[i].name = names[i];
		for ( int j=0; j < 8; j++ ) {
			s[i].marks[j] = marks[i][j];
		}
	}

	for( int i=0; i < 40; i++ ) {
		total = s[i].marks[0] + s[i].marks[1] + s[i].marks[2] + s[i].marks[3] + s[i].marks[4] + s[i].marks[5] + s[i].marks[6] + s[i].marks[7];
		printf("Name: %s subject marks : %d %d %d %d %d %d %d %d Total: %d\n", s[i].name, s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].marks[3], s[i].marks[4], s[i].marks[5], s[i].marks[6], s[i].marks[7], total);
		total = 0;
	}


  END_BENCH();

  print_bench ();

	return 0;
}
#endif
