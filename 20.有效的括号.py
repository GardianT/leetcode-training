#
# @lc app=leetcode.cn id=20 lang=python
#
# [20] 有效的括号
#

# @lc code=start
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dic = {
            "{": "}",
            "(": ")",
            "[": "]",
            "}": "",
            ")": "",
            "]": ""
        }
        res = []
        for i in s:
            if len(res) == 0:
                res.append(i)
            else:
                if i == dic[res[-1]]:
                    res = res[:-1]
                else:
                    res.append(i)
        return len(res) == 0
# @lc code=end

