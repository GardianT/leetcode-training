/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        
        if (root == nullptr) {
            return ret;
        }
        //preorder(root);
        stack<TreeNode*> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            TreeNode* current = tmp.top();
            tmp.pop();
            ret.push_back(current->val);
            if (current->right != nullptr) {
            tmp.push(current->right);
            }
            if (current->left != nullptr) {
            tmp.push(current->left);
            }
        }
        return ret;
    }
    void preorder(TreeNode* root) {
        if (root != nullptr) {
            ret.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
};
// @lc code=end

