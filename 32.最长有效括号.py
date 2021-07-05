#
# @lc app=leetcode.cn id=32 lang=python
#
# [32] 最长有效括号
#

# 思路：用一个栈记录括号位置，每匹配成功一个括号，就把左右括号出现的位置放到一个数组里。
# 数组排序以后，他的最大连续区间就是最长有效括号串。
# @lc code=start
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        st, bitmap = [], [0] * len(s)
        for i, c in enumerate(s):
            if c == '(':
                st.append(i)
            elif st:
                bitmap[i], bitmap[st.pop()] = 1, 1

        res, tmp = 0, 0
        for i in bitmap:
            if i == 1:
                tmp += 1
            else:
                res = max(tmp, res)
                tmp = 0
        return max(res, tmp)
# @lc code=end

