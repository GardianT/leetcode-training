#
# @lc app=leetcode.cn id=47 lang=python
#
# [47] 全排列 II
#

# @lc code=start
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def foo(candis, cur, res):
            if len(candis) == 0 and cur not in res:
                res.append(cur)
                return
            for i in candis:
                tmp_candis = candis[:]
                tmp_candis.remove(i)
                foo(tmp_candis, cur + [i], res)
        res = []
        foo(nums, [], res)
        return res
# @lc code=end

