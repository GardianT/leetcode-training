/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> current;
        pathSum(root, targetSum, current, res);
        return res;
    }
    void pathSum(TreeNode* root, int target, vector<int> current, 
            vector<vector<int>>& res) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == target) {
                auto tmp = current;
                tmp.push_back(root->val);
                res.push_back(tmp);
            }
            return;
        }
        auto tmp = current;
        tmp.push_back(root->val);
        auto left = target - root->val;
        pathSum(root->left, left, tmp, res);
        pathSum(root->right, left, tmp, res);
        return;
    }
};
// @lc code=end

