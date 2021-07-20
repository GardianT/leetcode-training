/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (const auto& i : nums) {
            if (i == 1) {
                count++;
            } else {
                res = max(count, res);
                count = 0;
            }
        }
        return max(count, res);
    }
};
// @lc code=end

