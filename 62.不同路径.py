#
# @lc app=leetcode.cn id=62 lang=python
#
# [62] 不同路径
#

# @lc code=start
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m == 1 or n == 1:
            return 1
        step = m + n - 2
        n1 = 1
        n2 = 1
        for i in range(min(m - 1, n - 1)):
            n1 *= (step - i)
            n2 *= min(m - 1, n - 1) - i
        return n1 / n2
# @lc code=end

