#
# @lc app=leetcode.cn id=70 lang=python
#
# [70] 爬楼梯
#

# @lc code=start
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 3:
            return n
        n1, n2 = 2, 3
        for i in range(3, n):
            n2, n1 = n1 + n2, n2
        return n2
# @lc code=end

