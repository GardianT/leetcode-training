#
# @lc app=leetcode.cn id=53 lang=python
#
# [53] 最大子序和
#

# @lc code=start
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0

        res = -9999999
        tmp = 0
        for i in nums:
            if tmp <= 0:
                tmp = i
            else:
                tmp = tmp + i
            res = max(tmp, res)
        return res
# @lc code=end

