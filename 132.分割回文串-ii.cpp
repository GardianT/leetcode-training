/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ret;

    int minCut(string s) {
        if (isf(s)) {
            return 0;
        }

        vector<string> tmp;
        foo(tmp, s);
        std::sort(ret.begin(), ret.end(), [](vector<string> a, 
                            vector<string> b) {
            return a.size() < b.size();
        });
        return ret[0].size() - 1;
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

