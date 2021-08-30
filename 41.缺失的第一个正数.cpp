/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
        int idx = 0;
        while (idx < nums.size()) {
            if (nums[idx] == idx + 1) {
                ++idx;
            } else {
                while (nums[idx] != idx + 1 && 
                        nums[idx] > 0 && 
                        nums[idx] <= nums.size() && 
                        nums[nums[idx] - 1] != nums[idx]) {
                    std::swap(nums[idx], nums[nums[idx] - 1]);
                }
                idx++;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
// @lc code=end

