/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    void add(int i, TreeNode*& root) {
        if (root == nullptr) {
            root = new TreeNode(i);
            return;
        }
        if (root->val < i) {
            add(i, root->right);
        } else {
            add(i, root->left);
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (const auto& i : preorder) {
            add(i, root);
        }
        return root;
    }
};
// @lc code=end

