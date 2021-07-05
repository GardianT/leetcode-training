/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 1;
        int mn = 1;
        int res = INT_MIN;
        for (const auto& i : nums) {
            if (i < 0) {
                std::swap(mx, mn);
            }
            mx = max(mx * i, i);
            mn = min(mn * i, i);
            res = max(res, mx);
        }
        return res;
    }
};
// @lc code=end

