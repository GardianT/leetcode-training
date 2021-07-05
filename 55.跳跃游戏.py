#
# @lc app=leetcode.cn id=55 lang=python
#
# [55] 跳跃游戏
#

# @lc code=start
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 0:
            return False
        
        max_dis = nums[0]
        for i in range(len(nums)):
            if i <= max_dis:
                max_dis = max(max_dis, nums[i] + i)
        return max_dis >= len(nums) - 1

# @lc code=end

