/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    void qsort(vector<int>& nums, int left, int right) {
        if (left > right) {
            return;
        }
        int l = left;
        int r = right;
        int split = nums[l];
        while (l < r) {
            while (l < r && nums[r] >= split) {
                r--;
            }
            nums[l] = nums[r];
            while (l < r && nums[l] <= split) {
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = split;
        qsort(nums, left, l - 1);
        qsort(nums, l + 1, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        //qsort(nums, 0, nums.size() - 1);
        sort( nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end

