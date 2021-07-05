/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

// @lc code=start
class Solution {
public:
    int minDays(int n) {
        if (n < 3) return n;
        if (n == 3) return 2;
        return min((n % 3) + minDays(n/3), (n % 2) + minDays(n / 2)) + 1;
    }
};
// @lc code=end

