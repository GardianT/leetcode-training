/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> tmp;
        vector<int> current;
        foo(nums, 0, current, tmp);
        vector<vector<int>> res;
        for (const auto& vec : tmp) {
            res.push_back(vec);
        }
        return res;
    } 
    void foo(const vector<int>& nums, int idx, 
                vector<int>& current, set<vector<int>>& res) {
        std::sort(current.begin(), current.end());
        res.insert(current);
        for (int i = idx; i < nums.size(); ++i) {
            vector<int> next = current;
            next.push_back(nums[i]);
            foo(nums, i + 1, next, res);
        }
    }
};
// @lc code=end

