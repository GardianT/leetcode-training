# 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
# 说明：每次只能向下或者向右移动一步。
# 示例:
# 输入:
# [
#   [1,3,1],
#   [1,5,1],
#   [4,2,1]
# ]
# 输出: 7
# 解释: 因为路径 1→3→1→1→1 的总和最小。

# 思路：动态规划
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        grid_len = len(grid[0])
        grid_dep = len(grid)
        dp = [ [0 for i in xrange(grid_len)] for j in xrange(grid_dep)]
        
        # reset first raw
        tmp = 0
        for i in xrange(grid_len):
            tmp += grid[0][i]
            dp[0][i] = tmp
        # start dp
        for j in xrange(1, grid_dep):
            for i in xrange(grid_len):
                if i == 0:
                    dp[j][i] = dp[j - 1][i] + grid[j][i]
                else:
                    dp[j][i] = min(dp[j - 1][i], dp[j][i - 1]) + grid[j][i]
        
        return dp[-1][-1]