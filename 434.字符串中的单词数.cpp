/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int sum = 0;
        bool flag = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && !flag) {
                flag = true;
                sum += 1;
            } else if (s[i] == ' ') {
                flag = false;
            }
        }
        return sum;
    }
};
// @lc code=end

