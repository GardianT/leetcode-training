/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        foo(nums, 0, current, res);
        return res;
    }
    void foo(const vector<int>& nums, int start_idx, 
            const vector<int>& current,
            vector<vector<int>>& res) {
        res.push_back(current);
        if (start_idx >= nums.size()) {
            return;
        }
        for (int i = start_idx; i < nums.size(); ++i) {
            auto next = current;
            next.push_back(nums[i]);
            foo(nums, i + 1, next, res);
        }
    }
};
// @lc code=end

