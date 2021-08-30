/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void foo(string current, int left, int right, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(current);
        }
        if (left > 0) {
            foo(current + "(", left - 1, right, res);
        }
        if (right > left) {
            foo(current + ")", left, right - 1, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        foo("", n, n, res);
        return res;
    }
};
// @lc code=end

