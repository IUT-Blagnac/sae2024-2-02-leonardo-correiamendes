import unittest
import analyse.Efficacite.efficacite27 as efficacite27

class TestEfficacite(unittest.TestCase):
    
    def test_rle(self):
        self.assertEqual("", efficacite27.RLE(""))
        self.assertEqual("1a1b1c", efficacite27.RLE("abc"))
        self.assertEqual("1a2b3c", efficacite27.RLE("abbccc"))
        self.assertEqual("3a1b2a", efficacite27.RLE("aaabaa"))
        self.assertEqual("1a1A1a", efficacite27.RLE("aAa"))
        self.assertEqual("9W4W", efficacite27.RLE("WWWWWWWWWWWWW"))

    def test_rle_recursif(self):
        self.assertEqual("", efficacite27.RLEit("", 1))
        self.assertEqual("", efficacite27.RLEit("", 3))

        self.assertEqual("1a1b1c", efficacite27.RLEit("abc", 1))
        self.assertEqual("1a2b3c", efficacite27.RLEit("abbccc", 1))
        self.assertEqual("3a1b2a", efficacite27.RLEit("aaabaa", 1))
        self.assertEqual("1a1A1a", efficacite27.RLEit("aAa", 1))

        self.assertEqual("111a111b111c", efficacite27.RLEit("abc", 2))
        self.assertEqual("311a311b311c", efficacite27.RLEit("abc", 3))

    def test_unRLE(self):
        self.assertEqual("", efficacite27.unRLE(""))
        self.assertEqual("abc", efficacite27.unRLE("1a1b1c"))
        self.assertEqual("abbccc", efficacite27.unRLE("1a2b3c"))
        self.assertEqual("aaabaa", efficacite27.unRLE("3a1b2a"))
        self.assertEqual("aAa", efficacite27.unRLE("1a1A1a"))
        self.assertEqual("WWWWWWWWWWWWW", efficacite27.unRLE("9W4W"))

    def test_unRLE_recursif(self):
        self.assertEqual("", efficacite27.unRLEit("", 1))
        self.assertEqual("", efficacite27.unRLEit("", 3))
        self.assertEqual("abc", efficacite27.unRLEit("1a1b1c", 1))
        self.assertEqual("abbccc", efficacite27.unRLEit("1a2b3c", 1))
        self.assertEqual("aaabaa", efficacite27.unRLEit("3a1b2a", 1))
        self.assertEqual("aAa", efficacite27.unRLEit("1a1A1a", 1))

        self.assertEqual("abc", efficacite27.unRLEit("111a111b111c", 2))
        self.assertEqual("abc", efficacite27.unRLEit("311a311b311c", 3))

if __name__ == '__main__':
    unittest.main() 