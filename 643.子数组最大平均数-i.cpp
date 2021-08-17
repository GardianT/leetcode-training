/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int tmp = sum;
        int l = 0;
        int r = k;
        while (r < nums.size()) {
            tmp += nums[r];
            tmp -= nums[l];
            sum = max(sum, tmp);
            r++;
            l++;
        }
        return sum / double(k);
    }
};
// @lc code=end

