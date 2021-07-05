/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> ret(s.size() + 1);
        ret[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i + 1; ++j) {
                auto sub = s.substr(j, i + 1 - j);
                if (founded(sub, wordDict) && ret[j]) {
                    ret[i+1] = true;
                    break;
                }
            }
        }
        return ret.back();
    }
    bool founded(string s, vector<string>& w) {
        return std::find(w.begin(), w.end(), s) != w.end();
    }

};
// @lc code=end

