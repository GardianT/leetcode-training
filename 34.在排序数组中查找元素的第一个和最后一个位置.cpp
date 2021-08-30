/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return {0, 0};
            } else {
                return {-1, -1};
            }
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                int l1 = mid;
                while (l1 - 1 >= 0 && nums[l1 - 1] == target) --l1;
                int r2 = mid;
                while (r2 + 1 < nums.size() && nums[r2 + 1] == target) ++r2;
                return {l1, r2};
            } else if (nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid - 1;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

