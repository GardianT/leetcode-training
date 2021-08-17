/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) {
            return true;
        }

        bool f = int(word[1]) < 97;
        if (f && word[0] >= 97) {
            return false;
        }
        for(int i = 2; i < word.size(); ++i) {
            if (int(word[i]) < 97 == f) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

