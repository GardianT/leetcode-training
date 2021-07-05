#
# @lc app=leetcode.cn id=15 lang=python
#
# [15] 三数之和
#

# 思路：sort后双指针。
# @lc code=start
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        res = []
        nums.sort()
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            while l < r:
                arr = [nums[i], nums[l], nums[r]]
                if sum(arr) == 0:
                    if arr not in res:
                        res.append(arr)
                    l += 1
                elif sum(arr) > 0:
                    r -= 1
                else:
                    l += 1
        return res
        
# @lc code=end

