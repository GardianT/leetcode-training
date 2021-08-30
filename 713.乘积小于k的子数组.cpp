/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 || k == 1) return 0;
        int l = 0;
        int prod = 1; //存储nums[l]~nums[r]的累积
        int res = 0;
        for(int r = 0; r < nums.size(); r++){
            prod *= nums[r];
            while(prod >= k){
                prod /= nums[l++];
            }
            res += r - l + 1;
        }
        return res;
    }
};
// @lc code=end

