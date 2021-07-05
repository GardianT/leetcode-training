/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ret;

    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        foo(tmp, s);
        return ret;
    }

    void foo(vector<string> tmp, string s) {
        if (s.size() == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (isf(s.substr(0, i + 1))) {
                auto next = tmp;
                next.push_back(s.substr(0, i+1));
                foo(next, s.substr(i+1));
            }
        }
    }
    bool isf(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

