#
# @lc app=leetcode.cn id=34 lang=python
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0 or target < nums[0]:
            return [-1, -1]
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) / 2
            if nums[mid] == target:
                l, r = mid, mid
                while (r+1) < len(nums) and nums[r+1] == target:
                    r += 1
                while (l-1) >= 0 and nums[l-1] == target:
                    l -= 1
                return [l, r]
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return [-1, -1]
# @lc code=end

