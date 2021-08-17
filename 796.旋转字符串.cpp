/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        return goal.size() >= s.size() && (goal + goal).find(s) != string::npos;
    }
};
// @lc code=end

