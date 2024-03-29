#
# @lc app=leetcode.cn id=41 lang=python
#
# [41] 缺失的第一个正数
#

# @lc code=start
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 1
        for i in range(len(nums)):
            while 1 <= nums[i] and nums[i] <= len(nums):
                swap_index = nums[i] - 1
                if nums[swap_index] != swap_index + 1:
                    nums[i], nums[swap_index] = nums[swap_index], nums[i]
                else:
                    break

        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1
# @lc code=end

