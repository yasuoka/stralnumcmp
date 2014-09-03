/*
 * Copyright (c) 2014 YASUOKA Masahiko <yasuoka@yasuoka.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/param.h>

#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

int
stralnumcmp(const char *a, const char *b)
{
	int		 ai, ac, ani, anc, bi, bc, bni, bnc, cmp;
	intmax_t	 an, bn;
	char		*err;

	ai = bi = ac = bc = 0;
	while (a[ai] != '\0' && b[bi] != '\0') {
		ani = isdigit(a[ai]);
		bni = isdigit(b[bi]);
		ac = bc = 0;

		do {
			++ac;
			anc = isdigit(a[ai + ac]);
			/* break if the "digit or not" become not equal */
			if ((ani && !anc) || (!ani && anc))
				break;
		} while (a[ai + ac] != '\0');

		do {
			++bc;
			bnc = isdigit(b[bi + bc]);
			if ((bni && !bnc) || (!bni && bnc))
				break;
		} while (b[bi + bc] != '\0');

		if (ani && bni) {	/* both are digit */
			an = strtoimax(a + ai, &err, 10);
			bn = strtoimax(b + bi, &err, 10);
			cmp = an - bn;
		} else {
			cmp = strncmp(a + ai, b + bi, MIN(ac, bc));
			if (cmp == 0 && ac != bc)
				return (ac - bc);
		}

		if (cmp != 0)
			return (cmp);
		ai = ai + ac;
		bi = bi + bc;
	}
	/* both of them are digit and both or one of them reaches nul char */

	return (ai - bi);	/* longer is bigger */
}
