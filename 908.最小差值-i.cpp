/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int minv(vector<int>& nums) {
        int res = nums[0];
        for (const auto& i : nums) {
            res = min(res, i);
        }
        return res;
    }
    int maxv(vector<int>& nums) {
        int res = nums[0];
        for (const auto& i : nums) {
            res = max(res, i);
        }
        return res;
    }
    int smallestRangeI(vector<int>& nums, int k) {
        return maxv(nums) - minv(nums) <= 2*k ? 0 : maxv(nums) - minv(nums) - 2 * k;
    }
};
// @lc code=end

