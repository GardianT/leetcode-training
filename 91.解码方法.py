#
# @lc app=leetcode.cn id=91 lang=python
#
# [91] 解码方法
#

# 思路：动态规划。
# f(n) = f(n - 1) if 当前位和前一位不能组成新编码
#      = f(n - 1) + f(n - 2) if 当前位和前一位能组成新编码
# 本质就是变形的跳台阶问题。
# @lc code=start
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s[0] == '0':
            return 0

        if len(s) < 2:
            return len(s)
        
        dp = [1, 1]
        for i in range(len(s)):
            cur = dp[-1]
            if s[i] == "0":
                cur = 0
            if i > 0 and (s[i-1] == "1" or (s[i-1] == "2" and s[i] <= "6")):
                cur += dp[-2]
            dp.append(cur)
            
        return dp[-1]
# @lc code=end

