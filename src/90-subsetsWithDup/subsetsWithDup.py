# Q:
# 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
# 说明：解集不能包含重复的子集。
# 示例:
# 输入: [1,2,2]
# 输出:
# [
#   [2],
#   [1],
#   [1,2,2],
#   [2,2],
#   [1,2],
#   []
# ]

# 思路：同78题
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