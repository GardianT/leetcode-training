/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long r = num;
        while (r * r > num) {
            r = (r + num/r) /2;
        }
        return r * r == num;
    }
};
// @lc code=end

