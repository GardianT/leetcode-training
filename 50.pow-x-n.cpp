/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        int i = abs(n);
        while (i != 0) {
            if (i % 2 != 0) {
                res *= x;
            }
            x *= x;
            i /= 2;
        }
        return n > 0 ? res : 1 / res;
    }
};
// @lc code=end

