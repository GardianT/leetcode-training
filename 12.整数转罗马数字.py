#
# @lc app=leetcode.cn id=12 lang=python
#
# [12] 整数转罗马数字
#

# @lc code=start
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        m = [
            ["", "M", "MM", "MMM"],
            ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
            ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
            ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        ]
        res = ""
        d = [1000, 100, 10, 1]
        for i in range(len(d)):
            v = d[i]
            res += m[i][ num/v ]
            num %= v
        return res
# @lc code=end

