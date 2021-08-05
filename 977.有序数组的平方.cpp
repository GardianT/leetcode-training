/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int i = 0;
        for (; i < nums.size();) {
            if (nums[i] < 0) {
                i++;
            } else {
                break;
            }
        }
        int j = i - 1;
        int idx = 0;
        while (i < nums.size() && j >= 0) {
            int val1 = nums[i] * nums[i];
            int val2 = nums[j] * nums[j];
            if (val1 > val2) {
                res[idx] = val2;
                j--;
            } else {
                res[idx] = val1;
                i++;
            }
            idx++;
        }
        while (i < nums.size()) {
            res[idx++] = nums[i] * nums[i++];
        }
        while (j >= 0) {
            res[idx++] = nums[j] * nums[j--];
        }
        return res;
    }
};
// @lc code=end

