/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:
    int cap;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for (const auto& i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        v.insert(std::lower_bound(v.begin(), v.end(), val), val);
        if (v.size() > cap) {
            v.erase(v.begin());
        }
        return v.front();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

