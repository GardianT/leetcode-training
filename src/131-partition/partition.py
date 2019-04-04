# Q:
# 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
# 返回 s 所有可能的分割方案。
# 示例:
# 输入: "aab"
# 输出:
# [
#   ["aa","b"],
#   ["a","a","b"]
# ]
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        res = []
        def dfs(tmp, s):
            if len(s) == 0:
                res.append(tmp)
            for i in range(0, len(s)):
                substr = s[0:i + 1]
                if substr == substr[::-1]:
                    nt = tmp[:]
                    nt.append(substr)
                    dfs(nt, s[i + 1:])
        dfs([], s)
        return res