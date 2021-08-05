/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0;
        bool tl = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') {
                cntA++;
            } else if (s[i] == 'L') {
                if (i < s.size() - 2 && s[i+1] == 'L' && s[i+2] == 'L') {
                    tl = true;
                }
            }
        }
        return cntA <= 1 && !tl;
    }
};
// @lc code=end

