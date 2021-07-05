#
# @lc app=leetcode.cn id=90 lang=python
#
# [90] 子集 II
#

# @lc code=start
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        sorted_res = []
        def count(start, num):  # 深度优先搜索
            if sorted(num[:]) not in sorted_res:
                res.append(num)
                sorted_res.append(sorted(num[:]))
            for i in range(start, len(nums)):
                count(i + 1, num + [nums[i]])
        count(0, [])
        return res
# @lc code=end

