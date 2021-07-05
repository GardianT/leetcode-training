#
# @lc app=leetcode.cn id=76 lang=python
#
# [76] 最小覆盖子串
#

# TLE
# @lc code=start
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if len(s) < len(t):
            return ""

        def contains(s1, s2):
            m = {}
            for i in s2:
                if i in m:
                    m[i] += 1
                else:
                    m[i] = 1
            for i in s1:
                if i in m:
                    m[i] -= 1
            for v in m.values():
                if v > 0:
                    return False
            return True

        l1, l2, res = 0, len(t), ""
        while l2 <= len(s):
            if l2 - l1 >= len(t):
                if contains(s[l1:l2], t):
                    if len(s[l1:l2]) == len(t):
                        return s[l1:l2]
                    if len(s[l1:l2]) < len(res) or res == "":
                        res = s[l1:l2]
                        l1 += 1
                    else:
                        l1 += 1
                else:
                    l2 += 1
        return res

# @lc code=end

