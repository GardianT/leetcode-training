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