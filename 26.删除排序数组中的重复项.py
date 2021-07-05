#
# @lc app=leetcode.cn id=26 lang=python
#
# [26] 删除排序数组中的重复项
#

# @lc code=start
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)
        cur = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[cur]:
                cur += 1
                nums[cur] = nums[i]
        return cur + 1
# @lc code=end

