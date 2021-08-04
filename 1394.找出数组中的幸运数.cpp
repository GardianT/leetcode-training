/*
 * @lc app=leetcode.cn id=1394 lang=cpp
 *
 * [1394] 找出数组中的幸运数
 */

// @lc code=start
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        for (const auto& i : arr) {
            m[i]++;
        }
        int res = -1;
        for (const auto& kv : m) {
            if (kv.first == kv.second) {
                res = kv.first;
            }
        }
        return res;
    }
};
// @lc code=end

