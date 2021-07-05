#
# @lc app=leetcode.cn id=58 lang=python
#
# [58] 最后一个单词的长度
#

# @lc code=start
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        tmp = s.split()
        return len(tmp[-1]) if len(tmp) > 0 else 0
# @lc code=end

