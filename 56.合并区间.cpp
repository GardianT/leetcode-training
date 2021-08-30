/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0]; 
            });
        vector<vector<int>> res;
        for (const auto& i : intervals) {
            if (res.empty()) {
                res.push_back(i);
            } else {
                if (i[0] >= res.back()[0] && i[1] <= res.back()[1]) {
                    continue;
                }
                if (i[0] <= res.back()[1] && i[1] > res.back()[1]) {
                    res.back()[1] = i[1];
                } else {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end

