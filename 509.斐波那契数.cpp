/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        int pre1 = 0;
        int pre2 = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = pre1;
            pre1 = pre2;
            pre2 = tmp + pre2;
        }
        return pre2;
    }
};
// @lc code=end

