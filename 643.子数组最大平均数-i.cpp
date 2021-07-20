/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
        }
        return sum / double(k);
    }
};
// @lc code=end

