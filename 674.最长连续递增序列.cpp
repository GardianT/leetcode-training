/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int l = 0;
        int r = 1;
        while (r < nums.size()) {
            if (nums[r] > nums[r - 1]) {
                r++;
            } else {
                res = max(r-l, res);
                l = r;
                r = r+1;
            }
        }
        return max(res, r - l);
    }
};
// @lc code=end

