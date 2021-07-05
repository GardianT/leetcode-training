/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, int l, int target, int& res) {
        if (l == nums.size()) {
            if (target == 0) {
                res += 1;
                
            }
            return;
        }
        dfs(nums, l+1, target + nums[l], res);
        dfs(nums, l+1, target - nums[l], res);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int res = 0;
        dfs(nums, 0, target, res);
        return res;
    }
};
// @lc code=end

