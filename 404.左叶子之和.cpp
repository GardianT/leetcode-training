/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int res = 0;
    bool f(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        return root->left == nullptr && root->right == nullptr;
    }
    void foo(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (f(root->left)) {
            res += root->left->val;
        }
        foo(root->left);
        foo(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        foo(root);
        return res;
    }
};
// @lc code=end

