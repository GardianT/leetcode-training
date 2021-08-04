/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        bool found = false;
        bool f = false;
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[i-1];
            if (diff == 0) {
                
            } else if (diff < 0) {
                if (!found) {
                    found = true;
                    f = false;
                    
                } else {
                    if (f) {
                        return false;
                    }
                }
            } else if (diff > 0) {
                if (!found) {
                    found = true;
                    f = true;
                } else {
                    if (!f) {
                        return false;
                    }
                }
            }

        }
        return true;
    }
};
// @lc code=end

