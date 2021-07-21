/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int res = 0;
        for (int i = 1; i <= num / 2; ++i) {
            if (num % i == 0) {
                res += i;
            }
        }
        return res == num;
    }
};
// @lc code=end

