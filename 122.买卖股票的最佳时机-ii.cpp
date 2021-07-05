/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> res;
        for (int i = 0; i < prices.size() - 1; ++i) {
            auto tmp = prices[i + 1] - prices[i];
            if (tmp > 0) {
                res.push_back(tmp);
            }
        }
        return std::accumulate(res.begin(), res.end(), 0);
    }
};
// @lc code=end

