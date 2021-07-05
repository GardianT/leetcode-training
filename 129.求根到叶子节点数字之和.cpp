/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } 
        vector<int> res;
        foo(root, 0, res);
        return accumulate(res.begin(), res.end(), 0);
    }

    void foo(TreeNode* root, int current, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        auto now = current * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(now);
            return;
        }
        foo(root->left, now, res);
        foo(root->right, now, res);
    }
};
// @lc code=end

