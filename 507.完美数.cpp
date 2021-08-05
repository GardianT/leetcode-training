/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i <= num/2; ++i) {
            if (num%i ==0) {
                sum += i;
            }
            if (sum > num) return false;
        }
        return sum == num;
    }
};
// @lc code=end

