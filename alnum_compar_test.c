/*
 gcc -Wall -O0 -o alnum_compar_test alnum_compar.c alnum_compar_test.c
 */
#include <stdlib.h>
#include <stdio.h>

#include "alnum_compar.h"

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
	ASSERT(alnum_compar("JPN-Z",	"JPN-A") > 0);	/* just a ascii sort */
	ASSERT(alnum_compar("2",	"1") > 0);	/* just a ascii sort */
	ASSERT(alnum_compar("10",	"9") > 0);
	ASSERT(alnum_compar("E10",	"E9") > 0);
	ASSERT(alnum_compar("10E",	"9E") > 0);
	ASSERT(alnum_compar("1.10",	"1.9") > 0);
	ASSERT(alnum_compar("aa11",	"11bba") > 0);
	ASSERT(alnum_compar("aaaa",	"aaaa") == 0);
	ASSERT(alnum_compar("010",	"8") > 0);	/* not a octal */
	ASSERT(alnum_compar("10000",	"010000") < 0);	/* longer is bigger */
	ASSERT(alnum_compar("010000",	"10000") > 0);	/* longer is bigger */
	if (failed != 0)
		abort();
	exit(EXIT_SUCCESS);
}
