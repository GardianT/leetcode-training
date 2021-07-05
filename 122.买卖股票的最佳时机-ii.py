#
# @lc app=leetcode.cn id=122 lang=python
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        arr1 = prices[0:-1]
        arr2 = prices[1:]
        return sum(map(lambda x, y: 0 if y - x <= 0 else y - x, arr1, arr2))
# @lc code=end

