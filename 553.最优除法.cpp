/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

// @lc code=start
class Solution {
public:
    string jn(vector<int>& num) {
        string res = "";
        for (auto i : num) {
            if (res != "") {
                res += "/";
            }
            res += std::to_string(i);
        }
        return res;
    }
    string optimalDivision(vector<int>& nums) {
        if (nums.size() <= 2) {
            return jn(nums);
        }
        string res = std::to_string(nums[0]);
        vector<int> tmp;
        for (int i = 1; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
        }
        res += "/(" + jn(tmp) +")";
        return res;
    }
};
// @lc code=end

