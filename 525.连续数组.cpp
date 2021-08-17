/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
<<<<<<< HEAD
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        map<int, int> tmp;
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == 0 && i > res) {
                res = i + 1;
            }
            if (tmp.find(sum) != tmp.end()) {
                res = max(res, i - tmp[sum]);
            } else {
                tmp[sum] = i;
            }
        }
        return res;
=======

>>>>>>> 5ba0f77df587e1b306c2504603748f137201863c
    }
};
// @lc code=end

