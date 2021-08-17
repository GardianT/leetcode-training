/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    void foo(vector<int>& nums, int i, int k) {
        int tmp = 0;
        for (int j = i; j < nums.size(); ++j) {
            tmp += nums[j];
            if (tmp == k) {
                res++;
            }
        }
    }
    int subarraySum(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        m[0] = {-1};
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp += nums[i];
            if (m.find(tmp - k) != m.end()) {
                res += m[tmp - k].size();
            }
            if (m.find(tmp) == m.end()) {
                m[tmp] = {i};
            } else {
                m[tmp].push_back(i);
            }

        }
        return res;
    }
};
// @lc code=end

