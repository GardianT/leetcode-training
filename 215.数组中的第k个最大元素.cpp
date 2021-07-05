/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return -1;
        }
        std::vector<int> tmp;
        for (const auto& i : nums) {
            tmp.insert(std::lower_bound(tmp.begin(), tmp.end(), i), i);
            if (tmp.size() > k) {
                tmp.erase(tmp.begin());
            }
        }
        return tmp.front();
    }
};
// @lc code=end

