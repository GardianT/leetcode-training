/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
public:
    // bool checkSubarraySum(vector<int>& nums, int k) {  
    //     for (int i = 0; i < nums.size() - 1; ++i) {
    //         int res = nums[i];
    //         for (int j = i+1; j < nums.size(); ++j) {
    //             res += nums[j];
    //             if (res % k == 0) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int sum = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int temp = sum % k;
            if(s.count(temp))   return true;
            s.insert(pre);
            pre = temp;
        }
        return false;
    }
};
// @lc code=end

