/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = 0;
        while (m < matrix[0].size()) {
            vector<int> tmp;
            for (int i = 0; i < matrix.size(); ++i) {
                
                tmp.push_back(matrix[i][m]);
            }
            res.push_back(tmp);
            m++;
        }
        return res;
    }
};
// @lc code=end

