/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minfoo(vector<int>& nums) {
        int res = nums[0];
        for (const auto& i : nums) {
            res = min(res, i);
        }
        return res;
    }
    int sumfoo(vector<int>& nums) {
        int res = 0;
        for (const auto& i : nums) {
            res += i;
        }
        return res;
    }
    int minMoves(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        return sumfoo(nums) - nums.size() * minfoo(nums);
    }
};
// @lc code=end

