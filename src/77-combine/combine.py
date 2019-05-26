# 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
# 示例:
# 输入: n = 4, k = 2
# 输出:
# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ]

def dfs(n, k, start, tmp, ret):
    if len(tmp) == k:
        ret.append(tmp[:])
    for i in range(start, n + 1):
        tmp.append(i)
        dfs(n, k, i + 1, tmp, ret)
        tmp.pop()

class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        tmp, ret = [], []
        dfs(n, k, 1, tmp, ret)
        return ret