/*
 gcc -Wall -O0 -o stralnumcmp_test stralnumcmp.c stralnumcmp_test.c
 */
#include <stdlib.h>
#include <stdio.h>

#include "stralnumcmp.h"

static int failed = 0;

#define ASSERT(_cond)							\
	do {								\
		if (!(_cond)) {						\
			fprintf(stderr, "ASSERT(%s) failed\n",		\
			    #_cond);					\
			failed++;					\
		}							\
	} while (0 /* CONSTCOND */)

int
main(int argc, char *argv[])
{
	ASSERT(stralnumcmp("JPN-Z",	"JPN-A") > 0);	/* just a ascii sort */
	ASSERT(stralnumcmp("2",	"1") > 0);	/* just a ascii sort */
	ASSERT(stralnumcmp("vic1",	"vic0") > 0);
	ASSERT(stralnumcmp("vic10",	"vic9") > 0);
	ASSERT(stralnumcmp("10",	"9") > 0);
	ASSERT(stralnumcmp("E10",	"E9") > 0);
	ASSERT(stralnumcmp("10E",	"9E") > 0);
	ASSERT(stralnumcmp("1.10",	"1.9") > 0);
	ASSERT(stralnumcmp("aa11",	"11bba") > 0);
	ASSERT(stralnumcmp("aaaa",	"aaaa") == 0);
	ASSERT(stralnumcmp("010",	"8") > 0);	/* not a octal */
	ASSERT(stralnumcmp("10000",	"010000") < 0);	/* longer is bigger */
	ASSERT(stralnumcmp("010000",	"10000") > 0);	/* longer is bigger */
	ASSERT(stralnumcmp("!11",	"aa") < 0);
	ASSERT(stralnumcmp("!11",	"11") < 0);

	if (failed != 0)
		abort();
	exit(EXIT_SUCCESS);
}
