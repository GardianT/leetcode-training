/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr || 
            (root->left == nullptr && root->right == nullptr)) {
                return true;
        }
        return isValid(root, -2147483647, 2147483647);
    }
    bool isValid(TreeNode* root, int left, int right) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= left || root->val >= right) {
            return false;
        }
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
};
// @lc code=end

