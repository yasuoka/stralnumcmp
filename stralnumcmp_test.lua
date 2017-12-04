require 'stralnumcmp';

assert(stralnumcmp('10km', '9km') > 0)
assert(stralnumcmp('part10.mp4', 'part9.mp4') > 0)
assert(stralnumcmp('9km', '10km') < 0)
assert(stralnumcmp('part9.mp4', 'part10.mp4') < 0)


-- just a ascii sort
assert(stralnumcmp("JPN-Z",    "JPN-A") > 0)
-- just a ascii sort
assert(stralnumcmp("2",        "1") > 0)
assert(stralnumcmp("vic1",     "vic0") > 0)
assert(stralnumcmp("vic10",    "vic9") > 0)
assert(stralnumcmp("10",       "9") > 0)
assert(stralnumcmp("E10",      "E9") > 0)
assert(stralnumcmp("10E",      "9E") > 0)
assert(stralnumcmp("1.10",     "1.9") > 0)
assert(stralnumcmp("aa11",     "11bba") > 0)
assert(stralnumcmp("aaaa",     "aaaa") == 0)
-- not a octal
assert(stralnumcmp("010",      "8") > 0)
-- longer is bigger
assert(stralnumcmp("10000",    "010000") < 0)
-- longer is bigger
assert(stralnumcmp("010000",   "10000") > 0)
