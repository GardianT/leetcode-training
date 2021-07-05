#
# @lc app=leetcode.cn id=455 lang=python
#
# [455] 分发饼干
#

# 贪心的方法，将饼干和小孩都倒序排列，然后饼干能最大满足的小孩+1
# @lc code=start
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        s.sort(reverse=True)
        g.sort(reverse=True)
        child = 0
        for i in g:
            if child < len(s) and s[child] >= i:
                child += 1
        return child
# @lc code=end

