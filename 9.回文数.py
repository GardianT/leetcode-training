#
# @lc app=leetcode.cn id=9 lang=python
#
# [9] 回文数
#

# @lc code=start
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        arr = []
        while x > 0:
            arr.append(x % 10)
            x /= 10
        return arr == arr[::-1]
# @lc code=end

