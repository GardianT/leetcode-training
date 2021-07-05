#
# @lc app=leetcode.cn id=633 lang=python
#
# [633] 平方数之和
#

# @lc code=start
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        l1, l2 = 0, 2 << 16
        while l1 <= l2:
            if (l1 * l1 + l2 * l2) > c:
                l2 -= 1
            elif (l1 * l1 + l2 * l2) < c:
                l1 += 1
            else:
                return True
        return False
# @lc code=end

