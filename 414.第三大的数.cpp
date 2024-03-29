/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max=-2147483649,mid=-2147483649,min=-2147483649;
        for(int i=0;i<nums.size();i++){
            if((nums[i]==max)||(nums[i]==mid)||(nums[i]==min)) continue;
            if(nums[i]>max){
                min=mid;
                mid=max;
                max=nums[i];
            }else if(nums[i]>mid){
                min=mid;
                mid=nums[i];
            }else if(nums[i]>min){
                min=nums[i];
            }
        }
        return min!=-2147483649?min:max;
    }
};
// @lc code=end

