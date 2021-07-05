#
# @lc app=leetcode.cn id=680 lang=python
#
# [680] 验证回文字符串 Ⅱ
#

# 双指针
# @lc code=start
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) <= 2:
            return True
        l1, l2 = 0, len(s) - 1
        while l1 < l2:
            if s[l1] == s[l2]:
                l1 += 1
                l2 -= 1
            else:
                s1 = s[l1+1:l2+1]
                s2 = s[l1:l2]
                return s1 == s1[::-1] or s2 == s2[::-1]
        return True
# @lc code=end

