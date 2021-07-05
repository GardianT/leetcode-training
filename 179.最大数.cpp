/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    bool onlyZero(string s) {
        bool flag = true;
        std::for_each(s.begin(), s.end(), [&flag](char a) {
            if (a != '0') {
                flag = false;
            }
        });
        return flag;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        std::for_each(nums.begin(), nums.end(), [&strs](int a) {
            strs.push_back(std::to_string(a));
        });
        std::sort(strs.begin(), strs.end(), [](string a, string b) {
            return std::stoll(a+b) > std::stoll(b+a);
        });
        string res;
        std::for_each(strs.begin(), strs.end(), [&res](string a){ 
            res+=a;
        });
        if (onlyZero(res)) {
            return "0";
        }
        return res;
    }
};
// @lc code=end

