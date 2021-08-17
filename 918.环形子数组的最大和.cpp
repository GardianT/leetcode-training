/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tmp = 0;
        int res1 = INT_MIN;
        for (const auto& i : nums) {
            if (tmp > 0) {
                tmp += i;
            } else {
                tmp = i;
            }
            res1 = max(res1, tmp);
        }

        tmp = 0;
        int res2 = INT_MAX;
        int total = 0;
        for (const auto& i : nums) {
            if (tmp < 0) {
                tmp += i;
            } else {
                tmp = i;
            }
            res2 = min(res2, tmp);
            total += i;
        }
        if (res1 < 0) {
            return res1;
        }
        return max(res1, total - res2);
    }
};
// @lc code=end

