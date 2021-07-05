/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        if (l1 == 0 || l2 == 0) {
            return 0;
        }

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                }
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
            }
        }
        return dp.back().back();
    }
};
// @lc code=end

