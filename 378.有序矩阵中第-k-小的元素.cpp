/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        vector<int> tp(matrix.size(), 0);
        while (res.size() < k) {
          int min_idx = 0;
          for (int i = 0; i < matrix.size(); i++) {
            if (tp[i] < matrix[0].size()) {
              min_idx = i;
              break;
            }
          }
          for (int i = 0; i < matrix.size(); ++i) {
            if (tp[i] < matrix[0].size() &&
              matrix[i][tp[i]] < matrix[min_idx][tp[min_idx]]) {
              min_idx = i;
            }
          }
          int val = matrix[min_idx][tp[min_idx]];
          tp[min_idx]++;
          res.insert(std::upper_bound(res.begin(), res.end(), val), val);
        }
        return res.back();
    }
};
// @lc code=end

