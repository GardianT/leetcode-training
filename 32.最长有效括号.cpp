/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) {
            return 0;
        }
        std::vector<int> v(s.size(), 0);
        stack<int> t;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (!t.empty()) {
                    v[i] = 1;
                    v[t.top()] = 1;
                    t.pop();
                }
            } else {
                t.push(i);
            }
        }
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 1) {
                tmp++;
            } else {
                res = max(res, tmp);
                tmp = 0;
            }
        }
        return max(res, tmp);
    }
};
// @lc code=end

