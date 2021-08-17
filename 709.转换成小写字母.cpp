/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        string res = s;
        for (int i = 0; i < res.size(); ++i) {
            if (isalpha(res[i]) && res[i] < 97) {
                res[i] += 32;
            }
        }
        return res;
    }
};
// @lc code=end

