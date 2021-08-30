/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* tmp = root;
        
        while (tmp) {
            if (tmp->val < val) { 
                if (tmp->right) {
                    tmp = tmp->right;
                } else {
                    tmp->right = new TreeNode(val);
                    break;
                }
            } else {
                if (tmp->left) {
                    tmp = tmp->left;
                } else {
                    tmp->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
// @lc code=end

