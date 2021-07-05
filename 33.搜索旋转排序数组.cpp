/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return foo(nums, 0, nums.size() - 1, target);
    }
    int foo(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < nums[right]) {
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

