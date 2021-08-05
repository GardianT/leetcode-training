/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
	void foo(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
		res = max(res, maxDepth(root->left) + maxDepth(root->right) + 1);
		foo(root->left);
		foo(root->right);
	}
    int diameterOfBinaryTree(TreeNode* root) {
        foo(root);
		return res - 1;
    }
};
// @lc code=end

