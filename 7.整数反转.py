#
# @lc app=leetcode.cn id=7 lang=python
#
# [7] 整数反转
#

# @lc code=start
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        x_str = str(x)
        res = ''
        if x_str[0] == '-':
            res += '-'
        res += x_str[::-1].lstrip('0').rstrip('-')
        res = int(res)
        if -2 ** 31 < res and res < 2 ** 31 - 1:
            return res
        return 0
# @lc code=end

