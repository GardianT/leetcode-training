/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotate_num = k % nums.size();
        if (rotate_num == 0) {
            return;
        } 
        reverse(nums, 0, nums.size() - rotate_num - 1);
        reverse(nums, nums.size() - rotate_num, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            std::swap(nums[l], nums[r]);
            ++l;
            --r;
        }
    }
};
// @lc code=end

