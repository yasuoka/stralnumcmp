import unittest
from stralnumcmp import stralnumcmp

class stralnumcmp_test(unittest.TestCase):
    def test(self):
        # just a ascii sort
        self.assertTrue(stralnumcmp("JPN-Z",    "JPN-A") > 0)
        # just a ascii sort
        self.assertTrue(stralnumcmp("2",        "1") > 0)
        self.assertTrue(stralnumcmp("vic1",     "vic0") > 0)
        self.assertTrue(stralnumcmp("vic10",    "vic9") > 0)
        self.assertTrue(stralnumcmp("10",       "9") > 0)
        self.assertTrue(stralnumcmp("E10",      "E9") > 0)
        self.assertTrue(stralnumcmp("10E",      "9E") > 0)
        self.assertTrue(stralnumcmp("1.10",     "1.9") > 0)
        self.assertTrue(stralnumcmp("aa11",     "11bba") > 0)
        self.assertTrue(stralnumcmp("aaaa",     "aaaa") == 0)
        # not a octal
        self.assertTrue(stralnumcmp("010",      "8") > 0)
        # longer is bigger
        self.assertTrue(stralnumcmp("10000",    "010000") < 0)
        # longer is bigger
        self.assertTrue(stralnumcmp("010000",   "10000") > 0)

if __name__ == '__main__':
    unittest.main()
