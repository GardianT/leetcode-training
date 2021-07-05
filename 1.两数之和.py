#
# @lc app=leetcode.cn id=1 lang=python
#
# [1] 两数之和
#

# @lc code=start
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = {}
        for (i, v) in enumerate(nums):
            if (target - v) in m.keys():
                return [i, m[target - v]]
            m[v] = i

# @lc code=end
