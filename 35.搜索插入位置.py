#
# @lc app=leetcode.cn id=35 lang=python
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target > nums[-1]:
            return len(nums)
        if target < nums[0]:
            return 0
        l, r = 0, len(nums) - 1
        while l <= r:
            if nums[l] == target:
                return l
            if nums[r] == target:
                return r
            mid = (l + r) / 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        return r + 1
# @lc code=end

