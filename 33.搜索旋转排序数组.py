#
# @lc app=leetcode.cn id=33 lang=python
#
# [33] 搜索旋转排序数组
#

# @lc code=start
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def foo(nums, l, r, target):
            if l > r:
                return -1
            if nums[l] == target:
                return l
            if nums[r] == target:
                return r

            mid = (l + r) / 2
            if nums[mid] == target:
                return mid
            
            if nums[mid] < nums[r]:
                if nums[mid] <= target and target <= nums[r]:
                    return foo(nums, mid + 1, r, target)
                else:
                    return foo(nums, l, mid - 1, target)
            else:
                if nums[l] <= target and target <= nums[mid]:
                    return foo(nums, l, mid - 1, target)
                else:
                    return foo(nums, mid + 1, r, target)

        return foo(nums, 0, len(nums) - 1, target)
# @lc code=end

