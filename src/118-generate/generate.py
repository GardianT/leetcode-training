# Q:
# 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
# 示例:
# 输入: 5
# 输出:
# [
#      [1],
#     [1,1],
#    [1,2,1],
#   [1,3,3,1],
#  [1,4,6,4,1]
# ]
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        for i in range(numRows):
            now = [1]*(i+1)
            if i >= 2:
                for n in range(1, i):
                    now[n] = pre[n - 1] + pre[n]
            result += [now]
            pre = now
        return result