/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int res = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            res = max(res, tmp);
        }
        return res;
    }
};
// @lc code=end

