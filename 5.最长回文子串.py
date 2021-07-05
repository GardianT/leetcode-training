#
# @lc app=leetcode.cn id=5 lang=python
#
# [5] 最长回文子串
#

# @lc code=start
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) < 2:
            return s
        res = ""
        def foo(st, i, j):
            cur = ""
            while i >= 0 and j <= len(st) -1:
                if st[i] == st[j]:
                    i -= 1
                    j += 1
                else:
                    break
            return st[i+1:j]

        for i in range(len(s)):
            s1 = foo(s, i, i)
            s2 = foo(s, i, i+1)
            if len(s1) > len(res):
                res = s1
            if len(s2) > len(res):
                res = s2
        return res
# @lc code=end

