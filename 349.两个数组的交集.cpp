/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }
        unordered_map<int, int> tmp;
        for (const auto& i : nums1) {
            tmp[i] = 1;
        }
        unordered_set<int> uni;
        for (const auto& i : nums2) {
            if (tmp.find(i) != tmp.end()) {
                uni.insert(i);
            }
        }
        vector<int> res;
        for (const auto& i : uni) {
            res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

