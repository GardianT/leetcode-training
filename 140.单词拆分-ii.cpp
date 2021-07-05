/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    vector<string> ret; 
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        foo(s, "", wordDict);
        return ret;
    }
    void foo(string s, string current, vector<string>& wordDict) {
        if (s.empty()) {
            ret.push_back(current);
            return;
        }
        for (int i = 1; i <= s.size(); ++i) {
            auto sub = s.substr(0, i);
            if (std::find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                auto next = current;
                if (!next.empty()) {
                    next += " ";
                }
                next += sub;
                foo(s.substr(i), next, wordDict);
            }
        }
    }
};
// @lc code=end

