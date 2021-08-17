/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 2);
        cost.insert(cost.begin(), 0);
        cost.insert(cost.end(), 0);
        for (int i = 0; i < cost.size(); ++i) {
            if (i <= 1) {
                dp[i] = cost[i];
            } else {
                dp[i] = min(dp[i-1], dp[i - 2]) + cost[i];
            }
        }
        return dp.back();
    }
};
// @lc code=end

