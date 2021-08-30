/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        int k = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            k = max(k, i + nums[i]);
            if (k <= i) {
                return false;
            }
            if (k >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

