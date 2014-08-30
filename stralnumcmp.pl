#
# Copyright (c) 2014 YASUOKA Masahiko <yasuoka@yasuoka.net>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

sub stralnumcmp($$)
{
	my ($a0, $b0) = (shift, shift);
	my $a = $a0;
	my $b = $b0;
	my $c;

	while (length($a) && length($b)) {
		my @a = $a =~ /^(\d+|\D+)(.*)$/;
		my @b = $b =~ /^(\d+|\D+)(.*)$/;

		if ($a[0] =~ /^\d/ && $b[0] =~ /^\d/) {
			$c = int($a[0]) - int($b[0]);
		} else {
			$c = $a[0] cmp $b[0];
		}
		return $c if ($c != 0);

		$a = $a[1];
		$b = $b[1];
	}

	return length($a0) - length($b0);
}

1;
