/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> m;
        set<std::pair<int, int>> res;
        for (const auto& i : nums) {
            if (m.find(k + i) != m.end()) {
                res.insert({max(i, k+i), min(i, k + i)});
            }
            if (m.find(i - k) != m.end()) {
                res.insert({max(i, i-k), min(i, i - k)});
            }
            m[i] = 1;
        }
        return res.size();
    }
};
// @lc code=end

