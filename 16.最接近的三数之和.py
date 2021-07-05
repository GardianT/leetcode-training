#
# @lc app=leetcode.cn id=16 lang=python
#
# [16] 最接近的三数之和
#

# 跟15题一样
# @lc code=start
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res = -999999
        nums.sort()
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            while l < r:
                arr = [nums[i], nums[l], nums[r]]
                if sum(arr) == target:
                    return target
                elif abs(sum(arr) - target) < abs(res - target):
                    res = sum(arr)
                if sum(arr) > target:
                    r -= 1
                else:
                    l += 1
        return res
# @lc code=end

