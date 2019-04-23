# Q:
# 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
# 示例 1:
# 输入: coins = [1, 2, 5], amount = 11
# 输出: 3 
# 解释: 11 = 5 + 5 + 1
# 示例 2:
# 输入: coins = [2], amount = 3
# 输出: -1

# 思路：dp[i]表示金额为i需要最少的金额多少,
# 对于任意金额j,dp[j] = min(dp[j],dp[j-coin]+1),如果j-coin存在的话.
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [float("inf") for i in range(amount + 1)]
        dp[0] = 0
        for i in range(1, amount + 1):
            for j in coins:
                if i - j >= 0:
                    dp[i] = min(dp[i], dp[i - j] + 1)
        return dp[-1] if dp[-1] != float("inf") else -1