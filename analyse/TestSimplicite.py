import unittest
import Simplicite.simplicite20 as simplicite20

class TestSimplicite(unittest.TestCase):
    
    def test_rle(self):
        self.assertEqual("", simplicite20.RLE(""))
        self.assertEqual("1a1b1c", simplicite20.encodage_rle("abc"))
        self.assertEqual("1a2b3c", simplicite20.encodage_rle("abbccc"))
        self.assertEqual("3a1b2a", simplicite20.encodage_rle("aaabaa"))
        self.assertEqual("1a1A1a", simplicite20.encodage_rle("aAa"))
        self.assertEqual("9W4W", simplicite20.encodage_rle("WWWWWWWWWWWWW"))

    def test_rle_recursif(self):
        self.assertEqual("", simplicite20.RLE_recursive("", 1))
        self.assertEqual("", simplicite20.RLE_recursive("", 3))

        self.assertEqual("1a1b1c", simplicite20.RLE_recursive("abc", 1))
        self.assertEqual("1a2b3c", simplicite20.RLE_recursive("abbccc", 1))
        self.assertEqual("3a1b2a", simplicite20.RLE_recursive("aaabaa", 1))
        self.assertEqual("1a1A1a", simplicite20.RLE_recursive("aAa", 1))

        self.assertEqual("111a111b111c", simplicite20.RLE_recursive("abc", 2))
        self.assertEqual("311a311b311c", simplicite20.RLE_recursive("abc", 3))

if __name__ == '__main__':
    unittest.main() 