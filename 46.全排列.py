#
# @lc app=leetcode.cn id=46 lang=python
#
# [46] 全排列
#

# @lc code=start
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def foo(candis, cur, res):
            if len(candis) == 0:
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

