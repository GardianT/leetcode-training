/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int last_pos = 0;
        string res;
        while (last_pos < s.size()) {
            while (s[last_pos] == ' ' && last_pos < s.size()) {
                last_pos++;
            }
            if (last_pos == s.size()) {
                break;
            }
            int pos = last_pos;
            while (s[pos] != ' ' && pos < s.size()) {
                pos++;
            }
            if (res == "") {
                res = s.substr(last_pos, pos - last_pos);
            } else {
                res = s.substr(last_pos, pos - last_pos) + " " + res;
            }
            last_pos = pos + 1;
        }
        return res;
    }
};
// @lc code=end

