/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();++i){
            if((nums[i]>=10&&nums[i]<100)||(nums[i]>=1000&&nums[i]<10000) || nums[i] == 100000)
                count++;
        }
        return count; 
    }
};
// @lc code=end

