/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int k = 0;
        int step = 0;
        int end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            k = max(k, i + nums[i]);
            if (k >= nums.size() - 1) {
                return step + 1;
            }
            if (end == i) {
                step++;
                end = k;
            }
        }
        return step;
    }
};
// @lc code=end

