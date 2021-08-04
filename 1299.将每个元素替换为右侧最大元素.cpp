/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        res.push_back(-1);
        int max_idx = arr.size() - 1;
        int max_val = arr.back();
        for (int i = arr.size() - 2; i >= 0; --i) {
            res.insert(res.begin(), max_val);
            if (arr[i] > max_val) {
                max_val = arr[i];
                max_idx = i;
            }
        }
        return res;
    }
};
// @lc code=end

