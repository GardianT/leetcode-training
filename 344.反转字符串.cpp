/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            std::swap(s[i], s[s.size() - 1 - i]);
        }
    }
};
// @lc code=end

