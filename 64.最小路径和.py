#
# @lc app=leetcode.cn id=64 lang=python
#
# [64] 最小路径和
#

# @lc code=start
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        tmp = [[0 for j in range(len(grid[0]))] for i in range(len(grid))]
        for i in range(len(grid[0])):
            if i == 0:
                tmp[0][i] = grid[0][i]
            else:
                tmp[0][i] = grid[0][i] + tmp[0][i-1]

        for i in range(1, len(grid)):
            for j in range(len(grid[0])):
                if j == 0:
                    tmp[i][j] = tmp[i - 1][j] + grid[i][j]
                else:
                    tmp[i][j] = min(tmp[i - 1][j], tmp[i][j - 1]) + grid[i][j]
        return tmp[-1][-1]

# @lc code=end

