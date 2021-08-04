/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res(nums.size());
        int l = 0;
        int r = nums.size() - 1;
        for (const auto& i : nums) {
            if (i % 2 == 0) {
                res[l++] = i;
            } else {
                res[r--] = i;
            }
        }
        return res;
    }
};
// @lc code=end

