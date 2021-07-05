/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k <= 0) {
            return res;
        }
        vector<int> candidates;
        for (int i = 0; i < n; ++i) {
            candidates.push_back(i+1);
        }
        vector<int> current;
        foo(candidates, 0, k, current, res);
        return res;
    }
    void foo(const vector<int>& candidates, 
            int start_idx, int total, const vector<int>& current, 
            vector<vector<int>>& res) {
        if (total == 0) { 
            res.push_back(current);
            return;
        }
        if (start_idx >= candidates.size()) {
            return;
        }
        for (int i = start_idx; i < candidates.size(); ++i) {
            auto next = current;
            next.push_back(candidates[i]);
            foo(candidates, i + 1, total - 1, next, res);
        }
        return;
    }
};
// @lc code=end

