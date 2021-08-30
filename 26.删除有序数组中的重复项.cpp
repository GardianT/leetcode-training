/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int idx = 0;
        int l = 1;
        while (l < nums.size()) {
            if (nums[l] != nums[idx]) {
                nums[++idx] = nums[l]; 
            }
            l++;
        }
        return idx + 1;
    }
};
// @lc code=end

