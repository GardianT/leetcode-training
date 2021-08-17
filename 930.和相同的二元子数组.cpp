/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> m;
        m[0] = 1;
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (m.find(sum - goal) != m.end()) {
                res += m[sum - goal];
            }
            m[sum] += 1;
        }
        return res;
    }
};
// @lc code=end

