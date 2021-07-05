#
# @lc app=leetcode.cn id=3 lang=python
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        k, res, m = -1, 0, {}
        for i, c in enumerate(s):
            if c in m and m[c] > k:
                k = m[c]
            else:
                res = max(res, i - k)
            m[c] = i
        return res
# @lc code=end

