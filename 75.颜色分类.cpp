/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                nums[num3++] = 2;
                nums[num2++] = 1;
                nums[num1++] = 0;
            } else if (nums[i] == 1) {
                nums[num3++] = 2;
                nums[num2++] = 1;
            } else {
                nums[num3++] = 2;
            }
        }
    }
};
// @lc code=end

