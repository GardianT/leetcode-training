#
# @lc app=leetcode.cn id=39 lang=python
#
# [39] 组合总和
#

# @lc code=start
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def foo(candis, target, tmp, res):
            if target == 0:
                if sorted(tmp) not in res:
                    res.append(sorted(tmp))
                return
            
            if target < 0:
                return

            for i in candis:
                nxt = tmp[:]
                nxt += [i]
                foo(candis, target - i, nxt, res)
        
        res = []
        foo(candidates, target, [], res)
        return res
# @lc code=end

