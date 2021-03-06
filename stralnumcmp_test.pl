require 'stralnumcmp.pl';

@t1 = qw(10km 9km);
@r1 = sort stralnumcmp @t1;
die unless $r1[0] eq '9km';
die unless $r1[1] eq '10km';

@t2 = qw(part10.mp4 part9.mp4);
@r2 = sort stralnumcmp @t2;
die unless $r2[0] eq 'part9.mp4';
die unless $r2[1] eq 'part10.mp4';

die unless(stralnumcmp('!11', '11') < 0);
die unless(stralnumcmp('!11', 'aa') < 0);
