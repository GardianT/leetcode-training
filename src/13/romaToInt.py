class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) < 1:
            return 0
        
        roma_map = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        res = 0
        pre_char = s[0]
        for i in xrange(len(s)):
            if roma_map[s[i]] > roma_map[pre_char]:
                res -= 2 * roma_map[pre_char]
            res += roma_map[s[i]]
            pre_char = s[i]
        return res