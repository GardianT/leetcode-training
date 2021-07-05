/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }
        if (nums.size() == 2) {
            std::swap(nums[0], nums[1]);
            return;
        }

        int r = nums.size() - 1;
        while (r >= 1) {
            if (nums[r] <= nums[r - 1]) {
                r--;
            } else {
                break;
            }
        }
        if (r == 0) {
            std::reverse(nums.begin(), nums.end());
        } else {
            for (int i = nums.size() - 1; i >= r; --i) {
                if (nums[i] > nums[r-1]) {
                    std::swap(nums[i], nums[r-1]);
                    break;
                }
            }
           
            std::sort(nums.begin() + r, nums.end());
        }
    }
};
// @lc code=end

