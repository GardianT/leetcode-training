/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int ret = -99999999;
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ret;
    }

    int maxSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto l = max(0, maxSum(root->left));
        auto r = max(0, maxSum(root->right));
        ret = max(ret, root->val + l + r);
        return max(l, r) + root->val;
    }
};
// @lc code=end

