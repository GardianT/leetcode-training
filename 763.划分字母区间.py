#
# @lc app=leetcode.cn id=763 lang=python
#
# [763] 划分字母区间
#

# 遍历每个字符的首尾位置，然后转变成了贪心的问题
# case不过，不过感觉是case不对呢
# @lc code=start
class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        if len(S) <= 1:
            return len(S)
        m = {c:i for i,c in enumerate(S)}
        
        res = []
        
        last_idx, cur_max = 0, 0
        for i, c in enumerate(S):
            cur_max = max(cur_max, m[c])
            if cur_max == i:
                res.append(cur_max - last_idx + 1)
                last_idx = i + 1

        return res
# @lc code=end

