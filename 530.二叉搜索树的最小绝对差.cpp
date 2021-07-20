/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int res = INT_MAX;
    int pre = INT_MIN;
    void update(int x) {
        if (pre == INT_MIN) {
            pre = x;
        } else {
            res = min(res, x - pre);
            pre = x;
        }
    }
    void foo(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        foo(root->left);
        update(root->val);
        foo(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        foo(root);
        return res;
    }
};
// @lc code=end

