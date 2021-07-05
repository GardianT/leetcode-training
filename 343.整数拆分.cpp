/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; j++) {
                dp[i + 1] = max(dp[i + 1], dp[i+1 - j] * j);
                dp[i+1] = max(dp[i+1], j*(i+1-j));
            }
        }
        return dp.back();
    }
};
// @lc code=end

