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