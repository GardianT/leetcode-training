#
# @lc app=leetcode.cn id=80 lang=python
#
# [80] 删除排序数组中的重复项 II
#

# @lc code=start
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        idx = 0
        for i in nums:
            if idx < 2 or i > nums[idx - 2]:
                nums[idx] = i
                idx += 1
        return idx
# @lc code=end

