/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        if (root->left != nullptr) {
            auto right = root->right;
            auto left = root->left;
            root->left = nullptr;
            root->right = left;
            while (root->right != nullptr) {
                root = root->right;
            }
            root->right = right;
        }
    }
};
// @lc code=end

