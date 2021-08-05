/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 数学问题
        // 假如s可以被n个str组成，那么s + s可以被2n个str组成
        // 去头尾变成 2n-2个str组成，所以n如果大于等于2，
        // 这个去头尾str可以找到s
        string tmp = s + s;
        return tmp.substr(1, tmp.size() - 2).find(s) != string::npos;
    }
};
// @lc code=end

