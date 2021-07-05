/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int t = b;
            b = max(b, a+nums[i]);
            a = t;
            int m = d;
            d = max(d, c+nums[i+1]);
            c = m;
        }
        return max(b, d);
    }
};
// @lc code=end

