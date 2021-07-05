/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
class Solution {
public:
    string res = "";
    void foo(string num, int k) {
        if (k == 0) {
            
            if (std::atoi(num.c_str()) < std::atoi(res.c_str())) {
                res = std::to_string(std::atoi(num.c_str()));
            }
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            string next = num;
            foo(next.erase(i, 1), k - 1);
        }
    }

    string removeKdigits(string num, int k) {
        res = num;
        foo(num, k);
        return res;
    }
};
// @lc code=end

