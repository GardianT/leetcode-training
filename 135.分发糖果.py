#
# @lc app=leetcode.cn id=135 lang=python
#
# [135] 分发糖果
#

# 从左到右遍历一遍，如果右边比左边的分数大，就以左边的+1
# 从右往左遍历一遍，如果左边比右边分数大，取 左边当前值和右边值+1 两者中的max
# @lc code=start
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        res = [1] * len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                res[i] = res[i - 1] + 1
        for i in reversed(range(len(ratings) - 1)):
            if ratings[i] > ratings[i + 1]:
                res[i] = max(res[i], res[i + 1] + 1)
        return sum(res)
# @lc code=end