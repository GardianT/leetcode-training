#
# @lc app=leetcode.cn id=78 lang=python
#
# [78] 子集
#

# @lc code=start
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def foo(target, cur, res):
            res.append(cur)
            if not target:
                return
            for i in target:
                tmp = target[:]
                tmp.remove(i)
                if not cur or i > cur[-1]:
                    foo(tmp, cur + [i], res)
        
        res = []
        foo(nums, [], res)
        return res
# @lc code=end

