/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        if (row_size == 0) {
            return false;
        }
        int col_size = matrix[0].size() - 1;
        int row_num = 0;
        while (row_num < row_size and col_size >= 0) {
            if (matrix[row_num][col_size] < target) {
                row_num++;
            } else if (matrix[row_num][col_size] > target) {
                col_size--;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

