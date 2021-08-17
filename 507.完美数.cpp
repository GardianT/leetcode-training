/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
<<<<<<< HEAD
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
=======
        int res = 0;
        for (int i = 1; i <= num / 2; ++i) {
            if (num % i == 0) {
                res += i;
            }
        }
        return res == num;
>>>>>>> 5ba0f77df587e1b306c2504603748f137201863c
    }
};
// @lc code=end

