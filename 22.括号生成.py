#
# @lc app=leetcode.cn id=22 lang=python
#
# [22] 括号生成
#

# @lc code=start
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def foo(l, r, n, cur, res):
            if l == n and r == n:
                res.append(cur)
                return
            if l < n:
                foo(l + 1, r, n, cur + "(", res)
            if r < l:
                foo(l, r + 1, n, cur + ")", res)

        res = []
        foo(0, 0, n, "", res)
        return res
# @lc code=end

