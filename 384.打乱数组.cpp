/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
public:
    vector<int> res;
    Solution(vector<int>& nums) {
        res = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> m = res;
        for (int i = 1; i < m.size(); ++i) {
            int r = rand() % (i+1);
            if (r != i) {
                swap(m[r], m[i]);
            }
        }
        return m;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

