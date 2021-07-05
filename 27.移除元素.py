#
# @lc app=leetcode.cn id=27 lang=python
#
# [27] 移除元素
#

# @lc code=start
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        l, r = 0, len(nums) - 1
        while l <= r:
            if nums[l] == val:
                nums[l] = nums[r]
                r -= 1
            else:
                l += 1
        return r + 1
# @lc code=end

