/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                current = nums[i];
                cnt = 1;
            } else {  
                if (current == nums[i]) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        return current;
    }
};
// @lc code=end

