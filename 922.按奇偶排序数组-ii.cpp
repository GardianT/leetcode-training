/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int l1 = 0;
        int l2 = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                res[l1] = nums[i];
                l1 += 2;
            } else {
                res[l2] = nums[i];
                l2 += 2;
            }
        }
        return res;
    }
};
// @lc code=end

