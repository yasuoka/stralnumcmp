stralnumcmp
===========

A comparator for text mixed alphabet and numeric characters in C,
Python, Perl, and Lua, which provides "natural sort" like the followings:

    9km
    10km

or

    part9.mp4
    part10.mp4

GNU libc has [strverscmp(3)](http://www.gnu.org/software/libc/manual/html_node/String_002fArray-Comparison.html#index-strverscmp-571)
in libc(3).  strverscmp(3) and this stralnumcmp() are similar, but they
differ the way of interpreting strings with leading zeros.
strverscmp(3) interprets leading zeros like decimal fractions, more
leading zeros is less, but this stralnumcmp() just ignores them.  eg.,
"01" > "002" in strverscmp(3), but "01" < "002" in stralnumcmp(3).


History
-------

- 2018-03-29 yasuoka
  - On python and lua implementation, comparing a numeric portion and a
    non numeric port which starts a char less than ``0`` didn't work
    properly
