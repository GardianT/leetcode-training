/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    struct tmp {
        int count;
        int start;
        int end;
        tmp(int i) : count(1), start(i), end(i) {}
    };
    int findShortestSubArray(vector<int>& nums) {
        map<int, tmp*> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end()) {
                m[nums[i]]->count++;
                m[nums[i]]->end = i;
            } else {
                m[nums[i]] = new tmp(i);
            }
        }
        int max = 1;
        int res = nums.size();
        for (const auto& kv : m) {
            if (kv.second->count > max) {
                res = kv.second->end - kv.second->start + 1;
            } else if (kv.second->count == max) {
                res = min(kv.second->end - kv.second->start + 1, res);
            }
            
        }
        return res;
    }
};
// @lc code=end

