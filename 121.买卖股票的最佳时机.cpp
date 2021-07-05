/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_p = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            res = max(res, prices[i] - min_p);
            min_p = min(prices[i], min_p);
        }
        return res;
    }
};
// @lc code=end

