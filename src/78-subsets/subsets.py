# Q:
# 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
# 说明：解集不能包含重复的子集。
# 示例:
# 输入: nums = [1,2,3]
# 输出:
# [
#   [3],
#   [1],
#   [2],
#   [1,2,3],
#   [1,3],
#   [2,3],
#   [1,2],
#   []
# ]

# 思路：dfs
# 还有一种解法：遍历 0 到 2**len(nums)。转换成二进制。
# 二进制中1的位置就代表取这个数字。也是最终结果。
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        def count(start, num):  # 深度优先搜索
            res.append(num)
            for i in range(start, len(nums)):
                count(i + 1, num + [nums[i]])
        count(0, [])
        return res