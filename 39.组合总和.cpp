/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    set<vector<int>> res;
    void foo(vector<int>& candidates, int target, const vector<int>& current) {
        if (target == 0) {
            if (!current.empty()) {
                auto tmp = current;
                std::sort(tmp.begin(), tmp.end());
                res.insert(tmp);
            }
            return;
        }
        if (target < 0) {
            return;
        }
        for (const auto& i : candidates) {
            auto next = current;
            next.push_back(i);
            foo(candidates, target - i, next);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        foo(candidates, target, {});
        vector<vector<int>> r;
        for (auto& i : res) {
            r.push_back(i);
        }
        return r;
    }
};
// @lc code=end

