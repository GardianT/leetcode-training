/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return foo(nums, 0, nums.size() - 1, target);
    }
    bool foo(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return false;
        }
        if (nums[left] == target) {
            return true;
        }
        if (nums[right] == target) {
            return true;
        }
        if (nums[left] == nums[right]) {
            for (int i = left; i < right; ++i) {
                if (nums[i] == target) {
                    return true;
                }
            }
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[mid] <= nums[right]) {
            if (nums[mid] < target && target < nums[right]) {
                return foo(nums, mid + 1, right, target);
            } else {
                return foo(nums, left, mid - 1, target);
            }
        } else {
            if (nums[left] < target && target < nums[mid]) {
                return foo(nums, left, mid - 1, target);
            } else {
                return foo(nums, mid + 1, right, target);
            }
        }
    }
};
// @lc code=end

