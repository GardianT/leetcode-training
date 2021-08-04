/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution {
public:
    int gcd (int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> m;
        for (const auto& i : deck) {
            m[i]++;
        }
        int res = 0;
        for (const auto& kv : m) {
            if (res == 0) {
                res = kv.second;
                if (res < 2) {
                    return false;
                }
            } else {
                if (gcd(kv.second, res) < 2) {
                    return false;
                } else {
                    res = gcd(kv.second, res);
                }
            }
        }
        return true;
    }
};
// @lc code=end

