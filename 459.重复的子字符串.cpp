/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = (s + s).substr(1, s.size() * 2 - 2);
        return tmp.find(s) != string::npos; 
    }
};
// @lc code=end

