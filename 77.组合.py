#
# @lc app=leetcode.cn id=77 lang=python
#
# [77] 组合
#

# @lc code=start
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def foo(target, num, cur, res):
            if num == 0:
                res.append(cur)
                return

            for i in target:
                tmp = target[:]
                tmp.remove(i)
                if not cur or i > cur[-1]:
                    foo(tmp, num - 1, cur + [i], res)

        res = []
        foo(range(1, n+1), k, [], res)
        return res
# @lc code=end

