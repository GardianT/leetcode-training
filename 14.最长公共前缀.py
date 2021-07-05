#
# @lc app=leetcode.cn id=14 lang=python
#
# [14] 最长公共前缀
#

# @lc code=start
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''
        if len(strs) == 1:
            return strs[0]
        
        sorted_strs = sorted(strs, key = lambda x: len(x))
        common_prefix = ''
        for i in xrange(len(sorted_strs[0])):
            for j in xrange(1, len(sorted_strs)):
                if sorted_strs[j][i] != sorted_strs[0][i]:
                    return common_prefix
            common_prefix += sorted_strs[0][i]
        return common_prefix
# @lc code=end

