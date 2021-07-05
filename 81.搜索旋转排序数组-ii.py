#
# @lc app=leetcode.cn id=81 lang=python
#
# [81] 搜索旋转排序数组 II
#

# @lc code=start
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        def foo(nums, l, r, target):
            if l > r:
                return False
            if nums[l] == nums[r]:
                for i in range(len(nums)):
                    if nums[i] == target:
                        return True
                return False
            
            if nums[l] == target:
                return True
            if nums[r] == target:
                return True     

            mid = (l + r) / 2
            if nums[mid] == target:
                return True
            
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

