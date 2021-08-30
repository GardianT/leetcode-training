/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        int l1 = abs(dividend);
        int l2 = abs(divisor);
        int res = 0;
        int tmp = 0;
        while (tmp <= l1) {
            res++;
            tmp += l2;
        }
        if (dividend < 0 && divisor < 0) {
            return res - 1;
        }
        if (dividend > 0 && divisor > 0) {
            return res - 1;
        }
        return 1 - res;
    }
};
// @lc code=end

