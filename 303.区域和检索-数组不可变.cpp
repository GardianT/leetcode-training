/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    int sum = 0;
    vector<int> l;
    vector<int> r;
    NumArray(vector<int>& nums) {
        r.resize(nums.size());
        l.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            l[i] = sum - nums[i];
        }
        int tmp_sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            tmp_sum += nums[i];
            r[i] = tmp_sum - nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sum - l[left] - r[right];
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

